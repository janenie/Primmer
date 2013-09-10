#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
//#include <grid.h>

using namespace std;

bool is_integer(const string &s) {
  string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end(); 
}

bool is_float(string s) {
  char *pEnd;
  float aim = strtol(s.c_str(), &pEnd, 10);
  return pEnd != NULL;
}

//expression evaluation
class reversePolish {
public:
  reversePolish(string s);
  ~reversePolish() { clear(); }
  bool valid() { return flag; }
  void printSuffix() { cout << result << endl; }
  void processOperands(char op);
  void compute();
  void clear() {
    while (!num.empty()) num.pop();
    while (!ops.empty()) ops.pop();
    result = "";
  }
private:
  stack<float> num;
  stack<char> ops;
  string result;
  bool flag;
};



reversePolish::reversePolish(string s) {
  flag = true;
  stack<string> match;
  int last = -1;
  istringstream si;
  si.str(s);
  string part;
  float n;
  char op;
  while (si >> part) {
    if (!flag) break;
    //cout << "part is " << part << endl;
    if (part.length() == 1)
      op = (part.c_str())[0];
    else op = (part.c_str())[1];
    //cout << "current char is "<< op << endl;
    switch(op) {
      case '+':
      case '-':
      case '*':
      case '/':
        if (last == 0) {
          processOperands(op);
          last = 1;
        } else flag = false;
        break;
      case '(':
        if (last == 1) {
          match.push(part);
          processOperands(op);
          last = 1;
        } else flag = false;
        break;
      case ')':
        if (last == 0) {
          if (!match.empty() && match.top() == "(") {
            match.pop();
            processOperands(op);
          } else flag = false;
        } else flag = false;
        break;
      default:
        if ((last == 1 || last == -1) && is_float(part)) {
          result += part + " ";
          last = 0;
        } else flag = false;
        break;
    }
    
  }
  //if (!flag) cout <<"the expression is wrong!" << endl;
  if (flag) {
    while (!ops.empty()) {
      char a = ops.top();
      result += a;
      result += " ";
      ops.pop();
    }
  }
}

void reversePolish::processOperands(char op) {
  char a;
  switch (op) {
    case '+':
    case '-':
      while (!ops.empty()) {
        a = ops.top();
        if (a == '(')
          break;
        result += a;
        result += " ";
        ops.pop();
      }
      ops.push(op);
      break;
    case '*':
    case '/':
      while (!ops.empty()) {
        a = ops.top();
        if (a == '(' || a == '+' || a == '-')
          break;
        result += a;
        result += " ";
        ops.pop();
      }
      ops.push(op);
      break;
    case '(':
      ops.push(op);
      break;
    case ')':
      while (!ops.empty() && ops.top() != '(') {
        a = ops.top();
        result += a;
        result += " ";
        ops.pop();
      }
      ops.pop();
      break;
  }
}

void reversePolish::compute() {
  if (!flag) {
    cout << "The expression is wrong, try another time" << endl;
  } else {
    istringstream op(result);
    string part;
    char a;
    float f1, f2;
    while (op >> part) {
      if (!flag) break;
      if (part.length() == 1)
        a = (part.c_str())[0];
      else a = (part.c_str())[1];
      switch (a) {
        case '+':
          if (!num.empty()) {
            f1 = num.top();
            num.pop();
          }
          if (!num.empty()) {
            f2 = num.top();
            num.pop();
          }
          num.push(f1 + f2);
          break;
        case '-':
          if (!num.empty()) {
            f1 = num.top();
            num.pop();
          }
          if (!num.empty()) {
            f2 = num.top();
            num.pop();
          }
          num.push(f2 - f1);
          break;
        case '*':
          if (!num.empty()) {
            f1 = num.top();
            num.pop();
          }
          if (!num.empty()) {
            f2 = num.top();
            num.pop();
          }
          num.push(f1 * f2);
          break;
        case '/':
          if (!num.empty()) {
            f1 = num.top();
            num.pop();
          }
          if (!num.empty()) {
            f2 = num.top();
            num.pop();
          }
          if (f1 - 0.0 > 1e-6)
            num.push(f2 / f1);
          else  {
            cout << "被除数为0！" << endl;
            flag = false;
          }
          break;
        default:
          num.push(atof(part.c_str()));
      }
    }
    float final;
    if (flag) {
      final = num.top();
      num.pop();
      cout << final << endl;
    }
  }
}
int main() {
  //initialize
  // Grid<double> matrix(3, 2);
  // for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 2; j++)
  //     matrix[i][j] = 0.0;
  // }
  
  string express;
  getline(cin, express);
  
  // string test = "3333";
  // char a = '7';
  // test += a;
  // cout << test << endl;
  reversePolish aim(express);
  if (aim.valid()) {
    aim.printSuffix();
    aim.compute(); 
  }
  else cout << "The expression is wrong!" << endl;
  
  
  return 0;
}