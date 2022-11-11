{
  /**
   * Type Aliases
   */
  type Text = string;
  const name: Text = "ian";
  const address: Text = "korea";
  type Num = number;
  type Student = {
    name: string;
    age: number;
  };
  const student: Student = {
    name: "ian",
    age: 12,
  };

  /**
   * String Literal Types
   */
  type Name = "name";
  let ianName: Name;
  ianName = "name";
  type JSON = "json";
  const json: JSON = "json";
}
