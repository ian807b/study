// 생성자 함수
// function Fruit(name, emoji) {
//   this.name = name;
//   this.emoji = emoji;
//   this.display = () => {
//     console.log(`${this.name}: ${this.emoji}`);
//   };
//   // return this; // Can omit
// }

// const apple = new Fruit('apple', '🍎');
// const orange = new Fruit('orange', '🍊');

// console.log(apple);
// console.log(orange);

// Class
class Fruit {
  constructor(name, emoji) {
    this.name = name;
    this.emoji = emoji;
  }
  display = () => {
    console.log(`${this.name}: ${this.emoji}`);
  };
}

const apple = new Fruit('apple', '🍎');
const orange = new Fruit('orange', '🍊');

console.log(apple);
console.log(orange);
console.log(apple.name);
apple.display();
