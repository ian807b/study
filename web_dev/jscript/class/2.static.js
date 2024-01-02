// static property, method
class Fruit {
  static MAX_FRUIT = 4; // Will not be a part of an instance
  constructor(name, emoji) {
    this.name = name;
    this.emoji = emoji;
  }

  // Class-level method (will not be a part of an instance)
  static makeRandomFruit() {
    // Class-level method cannot reference 'this'
    return new Fruit('banana', '🍌');
  }

  // Instance-level method
  display = () => {
    console.log(`${this.name}: ${this.emoji}`);
  };
}

// Fruit.name; // ❌
// Fruit.display(); // ❌

const banana = Fruit.makeRandomFruit();
console.log(banana); // Fruit { display: [Function: display], name: 'banana', emoji: '🍌' }

// Instance-level properties and methods
const apple = new Fruit('apple', '🍎');
const orange = new Fruit('orange', '🍊');

console.log(apple);
console.log(orange);
console.log(apple.name);
apple.display();

// Math.pow();
// Number.isFinite(1);
