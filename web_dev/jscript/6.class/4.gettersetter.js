// Accessor property
class Student {
  constructor(firstName, lastName) {
    this.firstName = firstName;
    this.lastName = lastName;
    // this.fullName = `${this.lastName} ${this.firstName}`;
  }
  get fullName() {
    return `${this.lastName} ${this.firstName}`;
  }
  set fullName(value) {
    console.log('set', value);
  }
}

const student = new Student('Ian', 'Hwang');
student.firstName = 'Anna';
console.log(student.firstName); // Anna
// console.log(student.fullName); // Hwnag Ian
// console.log(student.fullName()); // Hwang Anna
console.log(student.fullName);
student.fullName = 'Einstein';
