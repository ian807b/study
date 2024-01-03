// Object literal { key: value }
// new Object()
// Object.create();
// key - string, number, symbol
// value - primitive, object (function)

let apple = {
  name: 'apple',
  'hello-bye': '🤚',
  0: 1,
  ['hello-bye1']: '🤚',
};

// In order to access property or object,
console.log(apple.name); // Dot notation
console.log(apple['hello-bye1']); // Bracket notation
apple['name']; // Bracket notation

// Add a property
apple.emoji = '🍎';
console.log(apple.emoji);

// Delet a property
delete apple.emoji;
console.log(apple.emoji);
