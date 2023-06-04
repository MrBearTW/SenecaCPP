// 1

// var myString = "hello, World!"
// console.log(myString.replace(/h/gi,""));


// 2

var marvelCharacters = ["Dr. Strange", "Mr. Stark", "Mr. Parker", "Ms. Maximoff", "The Hulk", "Capt. America"];

function checkTitle(title) {
  return title.startsWith("Mr.") || title.startsWith("Ms.") || title.startsWith("Dr.");
}

var ans = [];
for(var i =0; i < marvelCharacters.length; i++)
{
    ans[i] = checkTitle(marvelCharacters[i]);
}
console.log(ans);


// var titleCheckArray = marvelCharacters.map(checkTitle);
// console.log(titleCheckArray);

// console.log(marvelCharacters.checkTitle());



//6
// var myString =
//   "The jumping, jolly Javascript astronauts are writing a jazzy quiz in QuizLand!";
// var regex = /Quiz/i;
// var newString = myString.replace(regex, "script");
// console.log(newString);



// 7
// var a = [1,2,3,4,5,6,7,8,9,10]
// a.push(11,12)
// var b = a.pop()
// var index = 10
// var c = a[index]
// console.log(c, a.indexOf(12), a.length)