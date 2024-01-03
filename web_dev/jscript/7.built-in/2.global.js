// console.log(globalThis);
// console.log(this);
// console.log(Infinity);
// console.log(NaN);
// console.log(undefined);

// eval('const num = 2; console.log(num)');
// console.log(isFinite(1));
// console.log(isFinite(Infinity));

console.log(parseFloat('12.43')); // string to num
console.log(parseInt('12.43')); // string to int
console.log(parseInt('11'));

// URL (URI, Uniform Resource Identifier)
// ASCII only
const URL = 'https://드림코딩.com';
const encoded = encodeURI(URL);
console.log(encoded);

const decoded = decodeURI(encoded);
console.log(decoded);

// Partial URL -> use component
const part = '드림코딩.com';
console.log(encodeURIComponent(part));
