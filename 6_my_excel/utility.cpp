#include "utils.h"

#include<iostream>
#include<fstream>
#include<ctime>

namespace MyExcel{
Vector::Vector(int n) : data(new std::string[n]), capacity(n), length(0) {}
void Vector::push_back(std::string s){
  if(capacity<=length){
    std::string *temp=new std::string[capacity*2];
    for(int i=0; i<length; i++)
      temp[i]=data[i];
    delete[] data;
    data=temp;
    capacity*=2;
  }
  
  data[length]=s;
  length++;
}
std::string Vector::operator[](int i) {return data[i];}
void Vector::remove(int x){
  for(int i=x+1; i<length; i++)
    data[i-1]=data[i];
  length--;
}
int Vector::size() {return length;}
Vector::~Vector(){
  if(data)
    delete[] data;
}

Stack::Stack() : start(NULL, "") {current=&start;}
void Stack::push(std::string s){
  Node *n=new Node(current, s);
  current=n;
}
std::string Stack::pop(){
  if(current==&start) return "";

  std::string s=current->s;
  Node *prev=current;
  current=current->prev;

  delete prev;
  return s;
}
std::string Stack::peek() {return current->s;}
bool Stack::is_empty(){
  if(current==&start) return true;
  return false;
}
Stack::~Stack(){
  while(current!=&start){
    Node *prev=current;
    current=current->prev;
    delete prev;
  }
}

NumStack::NumStack() : start(NULL, 0) {current=&start;}
void NumStack::push(double s){
  Node *n=new Node(current, s);
  current=n;
}
double NumStack::pop(){
  if(current==&start) return 0;
  double s=current->s;
  Node *prev=current;
  current=current->prev;

  delete prev;
  return s;
}
double NumStack::peek() {return current->s;}
bool NumStack::is_empty(){
  if(current==&start) return true;
  return false;
}
NumStack::~NumStack(){
  while(current!=&start){
    Node *prev=current;
    current=current->prev;
    delete prev;
  }
}

Cell::Cell(int x, int y, Table *table) : x(x), y(y), table(table) {}
StringCell::StringCell(std::string data, int x, int y, Table *t)
  : data(data), Cell(x, y, t) {}
std::string StringCell::stringify() {return data;}
int StringCell::to_numeric() {return 0;}

NumberCell::NumberCell(int data, int x, int y, Table *t)
  : data(data), Cell(x, y, t) {}
std::string NumberCell::stringify() {return std::to_string(data);}
int NumberCell::to_numeric() {return data;}

std::string DataCell::stringify(){
  char buf[50];
  tm temp;
  localtime(&temp, &data);
  
  strftime(buf, 50, "%F", &temp);

  return std::string(buf);
}
int DataCell::to_numeric() {return static_cast<int>(data);}
DataCell::DataCell(std::string s, int x, int y, Table *t) : Cell(x, y, t){
  int year=atoi(s.c_str());
  int month=atoi(s.c_str() + 5);
  int day=atoi(s.c_str() + 8);

  tm timeinfo;

  timeinfo.tm_year= year - 1900;
  timeinfo.tm_mon= month - 1;
  timeinfo.tm_mday= day;
  timeinfo.tm_hour= 0;
  timeinfo.tm_min= 0;
  timeinfo.tm_sec= 0;

  data=mktime(&timeinfo);
}
int ExprCell::to_numeric(){
  double result=0;
  NumStack stack;

  for(int i=0; i<exp_vec.size(); i++){
    std::string s=exp_vec[i];

    if(isalpha(s[0])){
      stack.push(table->to_numeric(s));
    }else if(isdigit(s[0])){
      stack.push(atoi(s.c_str()));
    }else{
      double y=stack.pop();
      double x=stack.pop();
      switch(s[0]){
        case '+':
          stack.push(x + y);
          break;
        case '-':
          stack.push(x - y);
          break;
        case '*':
          stack.push(x*y);
          break;
        case '/':
          stack.push(x/y);
          break;
      }
    }
  }
  return stack.pop();
}

Table::Table(int max_row_size, int max_col_size)
  : max_row_size(max_row_size), max_col_size(max_col_size){
  data_table=new Cell**[max_row_size];
  for(int i=0; i<max_row_size; i++){
    data_table[i]=new Cell*[max_col_size];
    for(int j=0; j<max_col_size; j++)
      data_table[i][j]=NULL;
  }
}
Table::~Table(){
  for(int i=0; i<max_row_size; i++)
    for(int j=0; j<max_col_size; j++)
      if(data_table[i][j]) delete data_table[i][j];
  for(int i=0; i<max_row_size; i++)
    delete[] data_table[i];
  delete[] data_table;
}
void Table::reg_cell(Cell *c, int row, int col){
  if(!(row<max_row_size && col<max_col_size)) return;
  if(data_table[row][col]) delete data_table[row][col];
  data_table[row][col]=c;
}
int Table::to_numeric(const std::string &s){
  int row=s[0] - 'A';
  int col=atoi(s.c_str() + 1) - 1;

  if(row<max_row_size && col<max_col_size)
    if(data_table[row][col])
      return data_table[row][col]->to_numeric();
  return 0;
}
int Table::to_numeric(int row, int col){
  if(row<max_row_size && col<max_col_size && data_table[row][col])
    return data_table[row][col]->to_numeric();
  return 0;
}
std::string Table::stringify(const std::string &s){
  int col=s[0] - 'A';
  int row=atoi(s.c_str() + 1) - 1;

  if(row<max_row_size && col<max_col_size)
    if(data_table[row][col])
      return data_table[row][col]->stringify();
  return 0;
}
std::string Table::stringify(int row, int col){
  if(row<max_row_size && col<max_col_size && data_table[row][col])
    return data_table[row][col]->stringify();
  return "";
}
std::ostream& operator<<(std::ostream &o, Table &table){
  o << table.print_table();
  return o;
}

TxtTable::TxtTable(int row, int col) : Table(row, col) {}
std::string TxtTable::print_table(){
  std::string total_table;

  int *col_max_wide=new int[max_col_size];
  for(int i=0; i<max_col_size; i++){
    unsigned int max_wide=2;
    for(int j=0; j<max_row_size; j++){
      if(data_table[j][i] &&
        data_table[j][i]->stringify().length()>max_wide)
        max_wide=data_table[j][i]->stringify().length();
    }
    col_max_wide[i]=max_wide;
  }

  total_table+="    ";
  int total_wide=4;
  for(int i=0; i<max_col_size; i++){
    if(col_max_wide[i]){
      int max_len=std::max(2, col_max_wide[i]);
      total_table+= " | " + col_num_to_str(i);
      total_table+=repeat_char(max_len - col_num_to_str(i).length(), ' ');

      total_wide+=(max_len + 3);
    }
  }

  total_table+="\n";
  for(int i=0; i<max_row_size; i++){
    total_table+=repeat_char(total_wide, '-');
    total_table+= "\n" + std::to_string(i + 1);
    total_table+=repeat_char(4 - std::to_string(i + 1).length(), ' ');

    for(int j=0; j<max_col_size; j++){
      if(col_max_wide[j]){
        int max_len=std::max(2, col_max_wide[j]);

        std::string s="";
        if(data_table[i][j])
          s=data_table[i][j]->stringify();
        total_table+= " | " + s;
        total_table+=repeat_char(max_len - s.length(), ' ');
      }
    }
    total_table+="\n";
  }
  return total_table;
}
std::string TxtTable::repeat_char(int n, char c){
  std::string s="";
  for(int i=0; i<n; i++) s.push_back(c);

  return s;
}
std::string TxtTable::col_num_to_str(int n){
  std::string s="";
  if(n<26){
    s.push_back('A' + n);
  }else{
    char first= 'A' + n/26 - 1;
    char second = 'A' + n%26;

    s.push_back(first);
    s.push_back(second);
  }
  return s;
}

HtmlTable::HtmlTable(int row, int col) : Table(row, col) {}
std::string HtmlTable::print_table(){
  std::string s="<table border='1' cellpadding='10'>";
  for(int i=0; i<max_row_size; i++){
    s+="<tr>";
    for(int j=0; j<max_col_size; j++){
      s+="<td>";
      if(data_table[i][j]) s+=data_table[i][j]->stringify();
      s+="</td>";
    }
    s+="</tr>";
  }
  s+="</table>";
  return s;
};

CSVTable::CSVTable(int row, int col) : Table(row, col) {}
std::string CSVTable::print_table(){
  std::string s="";
  for(int i=0; i<max_row_size; i++){
    for(int j=0; j<max_col_size; j++){
      if(j>=1) s+=",";
      std::string temp;
      if(data_table[i][j]) temp=data_table[i][j]->stringify();

      for(int k=0; k<temp.length(); k++){
        if(temp[k]=='"'){
          temp.insert(k, 1, '"');
          k++;
        }
      }
      temp= '"' + temp + '"';
      s+=temp;
    }
    s+="\n";
  }
  return s;
}
}

int main(){
  MyExcel::TxtTable table(5, 5);
  std::ofstream out("test.txt");

  table.reg_cell(new MyExcel::Cell("Hello~", 0, 0, &table), 0, 0);
  table.reg_cell(new MyExcel::Cell("C++", 0, 1, &table), 0, 1);

  table.reg_cell(new MyExcel::Cell("Programming", 1, 1, &table), 1, 1);
  std::cout << std::endl << table;
  out << table;


  MyExcel::CSVTable table1(5, 5);
  std::ofstream out1("test.csv");

  table1.reg_cell(new MyExcel::Cell("Hello~", 0, 0, &table1), 0, 0);
  table1.reg_cell(new MyExcel::Cell("C++", 0, 1, &table1), 0, 1);

  table1.reg_cell(new MyExcel::Cell("Programming", 1, 1, &table1), 1, 1);
  out1 << table1;


  MyExcel::HtmlTable table2(5, 5);
  std::ofstream out2("test.html");

  table2.reg_cell(new MyExcel::Cell("Hello~", 0, 0, &table2), 0, 0);
  table2.reg_cell(new MyExcel::Cell("C++", 0, 1, &table2), 0, 1);

  table2.reg_cell(new MyExcel::Cell("Programming", 1, 1, &table2), 1, 1);
  out2 << table2;
}