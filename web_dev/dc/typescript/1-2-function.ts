{
  // function Add(num1: number, num2: number): number {
  //   // some code...
  //   return num1 + num2;
  // }

  // function FetchNum(id: string): Promise<number> {
  //   // some code...
  //   return new Promise((resolve, reject) => {
  //     resolve(100);
  //   });
  // }

  // Option parameter
  function printName(firstName: string, lastName?: string) {
    console.log(firstName);
    console.log(lastName);
  }

  printName("Steve", "Jobs");
  printName("Ellie");
  printName("Anna", undefined);

  // Default parameter
  function printMessage(message: string = "default message") {
    console.log(message);
  }
  printMessage();

  // Rest parameter
  function addNumbers(...numbers: number[]): number {
    return numbers.reduce((a, b) => a + b);
  }
  console.log(addNumbers(1, 2));
  console.log(addNumbers(1, 2, 3, 4));
  console.log(addNumbers(1, 2, 3, 4, 5, 0));
}
