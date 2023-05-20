function twosquared() {
    return 2 * 2
}

console.log(twosquared())

var square = function (n) {
    return n * n
}

console.log(square(3))


function student(assignment1, assignment2, bonus){
    if(bonus){
        var finalGrade = assignment1/50 + assignment2/50 + bonus
    }else{
        var finalGrade = assignment1/50 + assignment2/50
    }
    return finalGrade
}

console.log(student(55,66,9))

Date.getTime()