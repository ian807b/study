const textObj = new String('Hello World!');
const text = 'Hello World!';
console.log(textObj);
console.log(text);

console.log(text.indexOf('l')); // 2
console.log(text.lastIndexOf('l')); // 9

console.log(text.includes('h'));
console.log(text.includes('H'));

console.log(text.startsWith('He'));
console.log(text.endsWith('He'));

console.log(text.toUpperCase());
console.log(text.toLowerCase());

console.log(text.substring(0, 2));
console.log(text.slice(2));
console.log(text.slice(-2));

const space = '                          space             ';
console.log(space.trim());

const longText = 'Get to the point';
console.log(longText.split(' '));
console.log(longText.split(' ', 2));
