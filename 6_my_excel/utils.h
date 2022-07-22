#ifndef UTILS_H
#define UTILS_H

#include<string>

namespace MyExcel{
class Vector{
  std::string *data;
  int capacity;
  int length;

 public:
  Vector(int n=1); // Default argument, 선언, 구현할 때 한 곳에서만 설정해야 됨
  void push_back(std::string s);
  std::string operator[](int i);
  void remove(int x);
  int size();
  ~Vector();
};
class Stack{
  struct Node{
    Node *prev;
    std::string s;

    Node(Node *prev, std::string s) : prev(prev), s(s) {}
  };

  Node *current;
  Node start;

 public:
  Stack();
  void push(std::string s);
  std::string pop();
  std::string peek();
  bool is_empty();
  ~Stack();
};
class NumStack{
  struct Node{
    Node *prev;
    double s;

    Node(Node *prev, double s) : prev(prev), s(s) {}
  };

  Node *current;
  Node start;

 public:
  NumStack();
  void push(double s);
  double pop();
  double peek();
  bool is_empty();

  ~NumStack();
};
class Table; class Cell{ // cpp로 컴파일 하면 필요 없을 듯?
 protected:
  int x, y;
  Table *table;

  std::string data;

 public:
  virtual std::string stringify();
  virtual int to_numeric();

  Cell(std::string data, int x, int y, Table *table);
};
class Table{
 protected:
  int max_row_size, max_col_size;

  Cell ***data_table;

 public:
  Table(int max_row_size, int max_col_size);

  ~Table();

  void reg_cell(Cell *c, int row, int col);
  int to_numeric(const std::string &s);
  int to_numeric(int row, int col);

  std::string stringify(const std::string &s);
  std::string stringify(int row, int col);

  virtual std::string print_table()=0;
};
class TxtTable : public Table{
  std::string repeat_char(int n, char c);
  std::string col_num_to_str(int n);

 public:
  TxtTable(int row, int col);

  std::string print_table();
};
class HtmlTable : public Table{
 public:
  HtmlTable(int row, int col);

  std::string print_table();
};
class CSVTable : public Table{
 public:
  CSVTable(int row, int col);

  std::string print_table();
};
}

#endif