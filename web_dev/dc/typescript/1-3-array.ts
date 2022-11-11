{
  // Array
  const fruits: string[] = ["tomato", "banana"];
  const scores: Array<number> = [1, 3, 4];
  // Both declarations are almost idenical except
  // you cannot use the second in the following case.
  function printArray(fruits: readonly string[]) {}

  // Tuple - can hold different types of variables
  // But rarely used -> use interface, type, or class instead
  let student: [string, number];
  student = ["name", 123];
  student[0]; // name
  student[1]; // 123
  const [name, age] = student;
}
