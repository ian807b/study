{
  /**
   * Intersection Types: &
   */
  type Student = {
    name: string;
    score: number;
  };

  type Worker = {
    employId: number;
    work: () => void;
  };

  function internWork(person: Student & Worker) {
    console.log(person.name, person.employId, person.work());
  }

  internWork({
    name: "ian",
    score: 1,
    employId: 123,
    work: () => {},
  });
}
