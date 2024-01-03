class Counter {
  #value;
  constructor(startValue) {
    if (isNaN(startValue) || startValue < 0) {
      this.#value = 0;
    } else {
      this.#value = startValue;
    }
  }
  get value() {
    return this.#value;
  }
  increment() {
    this.#value++;
  }
  display() {
    console.log(this.#value);
  }
}

const cnt = new Counter(3);
cnt.increment();
cnt.display();
cnt.increment();
cnt.display();
cnt.increment();
cnt.value = 100;
cnt.display();
