// One char per line
const text = 'Hello World!';
for (let i = 0; i < text.length; i++) {
  console.log(text[i]);
}

// Store id's into an array
const ids = 'user1, user2, user3, user4';
const idsArr = ids.split(', ');
console.log(idsArr);

// Print time every second
setInterval(() => {
  const now = new Date();
  console.log(now);
}, 1000);
