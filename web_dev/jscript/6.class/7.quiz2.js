class Employee {
  constructor(name, departName, hrsWorked, payRate) {
    this.name = name;
    this.departName = departName;
    this.hrsWorked = hrsWorked;
    this.payRate = payRate;
  }
  findWage = () => {
    return this.hrsWorked * this.payRate;
  };
}

class FullTimer extends Employee {
  static #PAY_RATE = 10000;
  constructor(name, departName, hrsWorked) {
    super(name, departName, hrsWorked, FullTimer.#PAY_RATE);
  }
}

class PartTimer extends Employee {
  static #PAY_RATE = 8000;
  constructor(name, departName, hrsWorked) {
    super(name, departName, hrsWorked, PartTimer.#PAY_RATE);
  }
}

const ian = new FullTimer('Ian', 'Engr', 30);
const john = new PartTimer('John', 'HR', 20);
console.log(ian.findWage());
console.log(john.findWage());
