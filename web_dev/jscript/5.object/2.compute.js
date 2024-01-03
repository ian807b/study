const obj = {
  name: 'Ian',
  age: 20,
};

// Static
obj.name;
obj.age;

// Dynamic
function getValue(obj, key) {
  return obj[key];
}
console.log(getValue(obj, 'name'));

function addKey(obj, key, value) {
  obj[key] = value;
}
addKey(obj, 'job', 'engineer');
console.log(obj);

function deleteKey(obj, key) {
  delete obj[key];
}
deleteKey(obj, 'age');
console.log(obj);
