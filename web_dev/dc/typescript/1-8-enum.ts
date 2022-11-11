{
  /**
   * Enum
   */
  // JavaScript doesn't have enum

  enum Days {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
  }
  console.log(Days.Monday);
  let day: Days = Days.Saturday;
  day = Days.Friday;
  day = 10;
  console.log(day);
}
