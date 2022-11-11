{
  /**
   * Type Assertions
   */
  function jsStrFunc(): any {
    return "hello";
  }
  const result = jsStrFunc();
  result as string;
}
