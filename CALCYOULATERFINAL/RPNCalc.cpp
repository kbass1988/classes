/* RPNCalc.cpp
 *  Kalead Bassma
 *  CS15M1
 *  Implementation of RPNCalc Program
 */

#include "RPNCalc.h"

RPNCalc::RPNCalc() { entry.stack.reserve(1); }

RPNCalc::~RPNCalc() { clear(); }

// Arithmetic functions

/* Name: add()
 *  Purpose: enables addition
 *  Parameters: None.
 *  Returns: adds the sum to the top of the stack
 */

void RPNCalc::add() {

  if (int_check() == true) {
    int first = entry.top().getInt();
    entry.pop();
    int second = entry.top().getInt();
    entry.pop();
    Datum sum(second + first);
    entry.push(sum);
  }
}

/* Name: multiply()
 *  Purpose: enables multiplication
 *  Parameters: None.
 *  Returns: adds the product to the top of the stack
 */

void RPNCalc::multiply() {

  if (int_check() == true) {
    int first = entry.top().getInt();
    entry.pop();
    int second = entry.top().getInt();
    entry.pop();
    Datum product(second * first);
    entry.push(product);
  }
}

/* Name: sub()
 *  Purpose: enables subtraction
 *  Parameters: None.
 *  Returns: adds the difference to the top of the stack
 */

void RPNCalc::sub() {

  if (int_check() == true) {
    int first = entry.top().getInt();
    entry.pop();
    int second = entry.top().getInt();
    entry.pop();
    Datum difference(
        second -
        first); // reverses to make sure order of operations is consistent
    entry.push(difference);
  }
}

/* Name: div()
 *  Purpose: enables division
 *  Parameters: None.
 *  Returns: adds the quotient to the top of the stack
 */

void RPNCalc::div() {
  if (int_check() == true) {
    int first = entry.top().getInt();
    entry.pop();
    int second = entry.top().getInt();
    entry.pop();
    Datum quotient(
        second /
        first); // reverses to make sure order of operations is consistent
    entry.push(quotient);
  }
}

/* Name: mod()
 *  Purpose: enables modulo operations
 *  Parameters: None.
 *  Returns: adds the remainder to the top of the stack
 */

void RPNCalc::mod() {
  if (int_check() == true) {
    int first = entry.top().getInt();
    entry.pop();
    int second = entry.top().getInt();
    entry.pop();
    Datum modulo(
        second %
        first); // reverses to make sure order of operations is consistent
    entry.push(modulo);
  }
}

/* Name: dup()
 *  Purpose: duplicates top of stack
 *  Parameters: None.
 *  Returns: a copy of the top datum on the stack
 */

void RPNCalc::dup() {
  Datum duplicate(entry.top());
  entry.push(duplicate);
}

/* Name: parseRString()
 *  Purpose: parses user input to create RStrings
 *  Parameters: user input taken as a stream.
 *  Returns: an RString
 */

string RPNCalc::parseRstring(std::istream &input) {
  int left_count = 1;
  int right_count = 0;
  std::vector<std::string> checker; // uses a stack
  checker.push_back(
      "{"); // For initial bracket. Activated after bracket is calld
  std::string rstring;

  std::string parse;

  string absorber;
  getline(input, parse); // converts whole line into string
  istringstream parser;
  parser.str(parse);
  for (int i = 0; i < parse.length(); i++) {
    absorber = parse[i]; // used due to integer error
    rstring.push_back(absorber[0]);
    if (rstring[i] == '}') {
      checker.pop_back();

    } else if (checker.empty()) {
      break;
    } else if (rstring[i] == '{') {
      checker.push_back("{"); // adds the bracket to the stack
    }
  }
  std::string::size_type i = parse.find(rstring);
  if (i != std::string::npos) {
    parse.erase(i, rstring.length());
  }

  if (!checker.empty()) {
    return " ";
  } else {
    if (parse.empty() == false) {
      rstring = '{' + rstring;
      Datum new_string(rstring);
      entry.push(new_string);
      parser.str(parse);
      read_input(parser);
      return " ";
    } else {

      // basecase
      return '{' + rstring;
    }
  }
}

/* Name: t()
 *  Purpose: creates a boolean value of "true"
 *  Parameters: none.
 *  Returns: adds a boolean data of true to the top of the stack
 */

void RPNCalc::t() {
  Datum t(true);
  entry.push(t);
}

/* Name: f()
 *  Purpose: creates a boolean value of "false"
 *  Parameters: none.
 *  Returns: adds a boolean data of false to the top of the stack
 */

void RPNCalc::f() {
  Datum f(false);
  entry.push(f);
}

/* Name: not()
 *  Purpose: reverses the boolean condition on the stack
 *  Parameters: none.
 *  Returns: adds the opposite boolean value to the stack
 */

void RPNCalc::not_() {
  if (entry.top().isBool()) {
    if (entry.top().getBool() == false) {
      entry.pop();
      Datum opposite(false);
      entry.push(opposite);
    } else {
      entry.pop();
      Datum opposite(true);
      entry.push(opposite);
    }
  } else {
    cerr << "Boolean is not in the stack" << endl;
  }
}

/* Name: drop()
 *  Purpose: removes the top most item from the stack
 *  Parameters: none.
 *  Returns: nothing.
 */

void RPNCalc::drop() { entry.pop(); }

// Comparison Operators

/* Name: compare_equal()
 *  Purpose: Performs "==" operation
 *  Parameters: none.
 *  Returns: Boolean value.
 */

void RPNCalc::compare_equal() {
  if (int_check() == true) {
    int second = entry.top().getInt();
    swap();
    int first = entry.top().getInt();
    swap();
    if (first == second) {
      entry.pop();
      t();
    } else {
      entry.pop();
      f();
    }
  }
}

/* Name: compare_greater()
 *  Purpose: Performs ">" operation
 *  Parameters: none.
 *  Returns: Boolean value.
 */

void RPNCalc::compare_greater() {
  if (int_check() == true) {
    int second = entry.top().getInt();
    swap();
    int first = entry.top().getInt();
    swap();
    if (first > second) {
      entry.pop();
      t();
    } else {
      entry.pop();
      f();
    }
  }
}

/* Name: compare_less()
 *  Purpose: Performs "<" operation
 *  Parameters: none.
 *  Returns: Boolean value.
 */

void RPNCalc::compare_less() {
  if (int_check() == true) {
    int second = entry.top().getInt();
    swap();
    int first = entry.top().getInt();
    swap();
    if (first < second) {
      entry.pop();
      t();
    } else {
      entry.pop();
      f();
    }
  }
}

/* Name: compare_lessOrEqual()
 *  Purpose: Performs "<=" operation
 *  Parameters: none.
 *  Returns: Boolean value.
 */

void RPNCalc::compare_lessOrEqual() {
  if (int_check() == true) {
    int second = entry.top().getInt();
    swap();
    int first = entry.top().getInt();
    swap();
    if (first <= second) {
      entry.pop();
      t();
    } else {
      entry.pop();
      f();
    }
  }
}
/* Name: compare_greaterOrEqual()
 *  Purpose: Performs ">=" operation
 *  Parameters: none.
 *  Returns: Boolean value.
 */

void RPNCalc::compare_greaterOrEqual() {
  if (int_check() == true) {
    int second = entry.top().getInt();
    swap();
    int first = entry.top().getInt();
    swap();
    if (first >= second) {
      entry.pop();
      t();
    } else {
      entry.pop();
      f();
    }
  }
}

/* Name: swap()
 *  Purpose: Swaps the top two items on the stack
 *  Parameters: none.
 *  Returns: The second stack value becomes the top and the top becomes the
 * second stack value
 */

void RPNCalc::swap() {
  Datum second(entry.top());
  entry.pop();
  Datum new_first(entry.top());
  entry.pop();
  entry.push(second);
  entry.push(new_first);
}

/* Name: clear()
 *  Purpose: Erases the stack.
 *  Parameters: none.
 *  Returns: A clear stack.
 */

void RPNCalc::clear() { entry.clear(); }

/* Name: print()
 *  Purpose: Outputs the topmost element of the stack to the stream.
 *  Parameters: none.
 *  Returns: Top of the stack to the user stream
 */

void RPNCalc::print() {
  if (entry.empty()) {
    cerr << "Stack is empty" << endl;
  } else {
    cout << entry.top().toString() << endl;
  }
}

/* Name: quit()
 *  Purpose: Ends the program.
 *  Parameters: none.
 *  Returns: A goodbye message.
 */

void RPNCalc::quit() {
  cerr << "“Thank you for using CalcYouLater." << endl;
  exit(0);
}

/* Name: run()
 *  Purpose: Driver function. Takes in user input and quits the program when "q"
 * is entered. Parameters: none. Returns: Nothing.
 */

void RPNCalc::run() {
  string input;
  while (cin) {
    read_input(cin);
  }

  quit();
}

/* Name: read_input()
 *  Purpose: Takes user input as a string then interprets that string as a
 * series of commands. Parameters: User input as an input stream. Returns: User
 * operation outputs.
 */

void RPNCalc::read_input(std::istream &user_input) {
  string input; // reads everything as a string
  string stream;
  istringstream line_stream;
  int data;

  getline(user_input, input);
  line_stream.str(input);
  while (line_stream >> stream) {
    if (stream == "{") {

      Datum RString(parseRstring(line_stream));
      entry.push(RString);
      if (entry.top().getRString() == " ") {
        entry.pop();
      }
    } else if (isdigit(stream[0])) { // Checks if its a digit
      data = stoi(stream);
      Datum new_entry(data);
      entry.push(new_entry);
    } else if (stream == "+") {
      add();
    } else if (stream == "*") {
      multiply();
    } else if (stream == "-") {
      sub();
    } else if (stream == "/") {
      div();
    } else if (stream == "%") {
      mod();
    } else if (stream == "dup") {
      dup();
    } else if (stream == "not") {
      not_();
    } else if (stream == "==") {
      compare_equal();
    } else if (stream == "<") {
      compare_less();
    } else if (stream == ">") {
      compare_greater();
    } else if (stream == "<=") {
      compare_lessOrEqual();
    } else if (stream == ">=") {
      compare_greaterOrEqual();
    } else if (stream == "q") {
      quit();
    } else if (stream == "if") {
      if_();
    } else if (stream == "#t") {
      t();
    } else if (stream == "#f") {
      f();
    } else if (stream == "not") {
      not_();
    } else if (stream == "exec") {
      exec();
    } else if (stream == "drop") {
      drop();
    } else if (stream == "file") {
      file();
    } else if (stream == "clear") {
      clear();
    } else if (stream == "print") {
      string if_checker;
      string if1 = "if";
      if_checker = entry.top().toString();
      if (if_checker.find(if1) != string::npos) {
        if_();
        print();
      } else {

        print();
      }
    }
  }


}
/* Name: exec()
 *  Purpose: Executes RStrings
 *  Parameters: none.
 *  Returns: Output of the RString operation
 */

void RPNCalc::exec() {
  if (entry.top().isRString() == false) {
    cerr << "Error, cannot accept input" << endl;
    clear();
    run();
  }

    istringstream parse; // converts R string into a normal stream to get piped
                         // into read_input
    string object;
    parse.str(entry.top().getRString());
    parse >> object; // dumps first bracket
    entry.pop();

    read_input(parse);
  
}

/* Name: file()
 *  Purpose: Reads RString files
 *  Parameters: none.
 *  Returns: File contents.
 */

void RPNCalc::file() {
  if (entry.top().isRString() == false) {
    cerr << "Error: file operand not string" << endl;
    clear();
    run();
  }
  ifstream infile;
  istringstream file_parser;
  string filename;
    string absorber;
    string large;
  file_parser.str(entry.top().getRString());
  file_parser >> filename; // dumps first bracket
  file_parser >> filename;
  file_parser.clear();
  entry.pop();
  infile.open(filename);
  if (infile.fail()) {
    cerr << "ERROR: Unable: to read " << filename << endl;
    clear();
    run();
  }

  // creates stringstream to store the file information
  string lines;
  while (!infile.eof()) {
    read_input(infile);  
   
  }
  infile.close();
  
}

/* Name: if()
 *  Purpose: Enables conditional operations.
 *  Parameters: Requires a boolean value, a false condition, and a true
 * condition. Returns: Executes a condition dependent on the initial boolean
 * statement
 */

void RPNCalc::if_() {
  // will just read the r string and ignore the "if"
  if (entry.top().isRString() == false) {
    cerr << "Error: expected rstring in if branch" << endl;
  }
  Datum false_condition(entry.top().getRString());

  entry.pop();
  if (entry.top().isRString() == false) {
    cerr << "Error: expected rstring in if branch" << endl;
  }
  Datum true_condition(entry.top().getRString());

  entry.pop();
  if (entry.top().isBool() == false) {
    cerr << "Error: expected boolean in if test" << endl;
  } else {
    if (entry.top().getBool() == true) {
      entry.pop();
      entry.push(true_condition);
      exec();
    } else {
      entry.pop();
      entry.push(false_condition);
      exec();
    }
  }
}


bool RPNCalc::int_check() {
  swap();
  if (entry.top().isInt() == false) {
    cerr << "Error: datum not int " << endl;
    swap();
    return false;
  } else {
    swap();
    return true;
  }
}