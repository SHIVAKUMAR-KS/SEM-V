// Define a main function, which is the entry point of a Dart program.
void main() {
  // Variables and data types
  int myNumber = 10;
  double myDouble = 3.14;
  String myString = 'Hello World';
  bool myBool = true;

  // Printing variables
  print('My number is: $myNumber');
  print('My double is: $myDouble');
  print('My string is: $myString');
  print('My boolean is: $myBool');

  // Basic arithmetic operations
  int result = myNumber + 5;
  print('Result of addition: $result');

  // Conditional statements
  if (myBool) {
    print('myBool is true');
  } else {
    print('myBool is false');
  }

  // Loops
  for (int i = 0; i < 5; i++) {
    print('Iteration $i');
  }

  // Lists
  List<int> numbers = [1, 2, 3, 4, 5];
  print('First element of the list: ${numbers[0]}');
  print('Length of the list: ${numbers.length}');

  // Maps
  Map<String, int> ages = {
    'Kiran': 30,
    'Raj': 25,
    'Alekya': 35,
  };
  print('Kiran\'s age: ${ages['Kiran']}');
}
