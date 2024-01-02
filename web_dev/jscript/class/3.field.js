// 접근제어자 - Encapsulation
// C++: private, public, protected
// JS: #, default
class Fruit {
  #name;
  #emoji;
  #type = 'fruit';
  constructor(name, emoji) {
    this.#name = name;
    this.#emoji = emoji;
  }
  #display = () => {
    console.log(`${this.#name}: ${this.#emoji}`);
  };
}

const apple = new Fruit('apple', '🍎');
// apple.name = 'orange';
console.log(apple);
