// class Tiger {
//   constructor(color) {
//     this.color = color;
//   }
//   eat() {
//     console.log('Eat!');
//   }
//   sleep() {
//     console.log('Sleep!');
//   }
// }

// class Dog {
//   constructor(color) {
//     this.color = color;
//   }
//   eat() {
//     console.log('Eat!');
//   }
//   sleep() {
//     console.log('Sleep!');
//   }
//   play() {
//     console.log('Play!');
//   }
// }

class Animal {
  constructor(color) {
    this.color = color;
  }
  eat() {
    console.log('Eat!');
  }
  sleep() {
    console.log('Sleep!');
  }
}

class Tiger extends Animal {}

const tiger = new Tiger('Yellow');
console.log(tiger);
tiger.sleep();
tiger.eat();

class Dog extends Animal {
  // Needs to accept the same parameter(s) as the parent
  constructor(color, ownerName) {
    super(color);
    this.ownerName = ownerName;
  }
  play() {
    console.log('Play!');
  }
  // Overriding
  eat() {
    // super.eat();
    console.log('Dog eats!');
  }
}

const dog = new Dog('Red', 'Ian');
console.log(dog);
dog.sleep();
dog.eat();
dog.play();
