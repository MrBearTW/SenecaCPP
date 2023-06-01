/**
 * WEB222 – Assignment 1
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been copied
 * manually or electronically from any other source (including web sites)
 * or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name: <YOUR_NAME>
 *      Student ID: <YOUR_STUDENT_ID>
 *      Date: <SUBMISSION_DATE>
 *
 * Please see all unit tests in the files problem-00.test.js, problem-01.test.js, etc.
 */

/*******************************************************************************
 * Problem 0: learn how to implement code to pass unit tests.
 *
 * Welcome to Assignment 1! In this assignment, you're going to be practicing lots
 * of new JavaScript programming techniques.  Before you dive in let's spend a
 * minute helping you learn how to read this code, and how to understand the
 * tests that go with it.
 *
 * In addition to this file, please also open the src/problem-00.test.js file.
 * Start by reading the comment at the top of that file, then come back here and
 * continue.
 *
 * Make sure you have completed the necessary Setup (install node.js, run `npm install`
 * before continuing).  The rest of the instructions assume that you have done this.
 *
 * After you finish reading src/problem-00.test.js, it's time to try running
 * the tests.  To run the tests, go to your terminal and type the following command:
 *
 *   npm test
 *
 * You have to run this command in the root of your project (i.e., in the same
 * directory as package.json).  When you do, you will see a lot of failures.
 * That's expected, since we haven't written any solution code yet.
 *
 * You can also run tests for only this problem instead of everything. To do that:
 *
 *   npm test problem-00
 *
 * This will look for tests that are part of the problem-00.test.js file, and only
 * run those.  Doing so should result in 1 failed and 1 passed test.
 *
 * The first test passes:
 *
 *  ✓ greeting should be a function (2ms)
 *
 * But the second one fails:
 *
 * ✕ greeting should return the correct string output (3ms)
 *
 * ● Problem 0 - greeting() function › greeting should  return the correct string output
 *
 *   expect(received).toBe(expected) // Object.is equality
 *
 *   Expected: "Hello WEB222 Student!"
 *   Received: "Hello WEB222 Student"
 *
 *     63 |   test('greeting should return the correct string output', function() {
 *     64 |     let result = greeting('WEB222 Student');
 *   > 65 |     expect(result).toBe('Hello WEB222 Student!');
 *        |                    ^
 *     66 |   });
 *     67 |
 *     68 |   /**
 *
 * We can see that the second test 'greeting should return the correct string output'
 * is failing. In particular, it's failing because it expected to get the string
 * "Hello WEB222 Student!" but instead it actually received the string "Hello WEB222 Student".
 *
 * It looks like we have a small typo in our code below, and we are missing
 * the final "!"" character.  Try adding it below, save this file, and re-run the
 * tests again:
 *
 * npm test problem-00
 * PASS  src/problem-00.test.js
 *  Problem 0 - greeting() function
 *   ✓ greeting should be a function (2ms)
 *   ✓ greeting should return the correct string output
 *
 * Test Suites: 1 passed, 1 total
 * Tests:       2 passed, 2 total
 *
 * Excellent! At this point you're ready to move on to Problem 1. As you do,
 * read both the information in the Problem's comment, and also read the tests
 * to understand what they expect from your code's implementation.
 *
 * One final word about these comments.  You'll see comments like this one:
 *
 * @param {string} name - the name to greet in the message
 * @returns {string}
 *
 * These are specially formatted comments that define parameters to functions,
 * and tell us the type (e.g., {string} or {number}), and also the parameter's name.
 * We also indicate the return type for functions.
 *
 * Finally, we also explain a bit about how the parameter is used, and what
 * data it will have, whether it's optional, etc.
 ******************************************************************************/

function greeting(name) {
  return `Hello ${name}`;
}

/*******************************************************************************
 * Problem 1: convert strings in snake_case to lowerCamelCase or UpperCamelCase.
 *
 * C programmers often use snake_case when naming functions or variables. In
 * JavaScript, we use lowerCamelCase (first letter lower case) or UpperCamelCase
 * (first letter Upper case) instead.
 *
 * You will write a function named toCamelCase() that accepts a string argument
 * and converts it from snake_case to camelCase.  The optional second argument
 * determines whether or not to produce UpperCamelCase or not.
 *
 * The toCamelCase() function should work like this:
 *
 * toCamelCase('variable') returns 'variable'
 * toCamelCase('variable_name') returns 'variableName'
 * toCamelCase('variable_name', true) returns 'VariableName' ()
 * toCamelCase('long_variable_name') returns 'longVariableName'
 * toCamelCase('multiple___underscores') returns 'multipleUnderscores'
 *
 * @param {string} name - a string variable name to be converted
 * @param {boolean} uppercase - (optional) whether to convert to UpperCamelCase
 *                              defaults to `false`
 * @return {string} - the converted camelCase version of the variable name
 ******************************************************************************/

function toCamelCase(name, uppercase) {
  // Replace this comment with your code...
}

/*******************************************************************************
 * Problem 2: create an HTML <meta> element with the given content.
 *
 * In HTML, a <meta> element is used to represent metadata about a web page. For
 * example: who is tha page's author?
 *
 * If I wanted to indicate that a web page was written by Kim Lee, I would use
 * the following <meta> tag:
 *
 *   <meta name="author" content="Kim Lee">
 *
 * See the following for more details about the <meta> tag:
 *
 *  - https://developer.mozilla.org/en-US/docs/Web/HTML/Element/meta
 *  - https://developer.mozilla.org/en-US/docs/Web/HTML/Element/meta/name
 *
 * Write a function named createMetaTag() which accepts both name and content values.
 * It should use these values to produce a new <meta> tag string. For example:
 *
 * createMetaTag('description', 'Course notes for WEB222')
 *
 * should return the following string of HTML:
 *
 * '<meta name="description" content="Course notes for WEB222">'
 *
 * Make sure you remove any leading or trailing whitespace from the name and content
 * values before you use them.
 *
 * createMetaTag('description', '          Course notes for WEB222              ')
 *
 * should return the following string of HTML:
 *
 * '<meta name="description" content="Course notes for WEB222">'
 *
 * Also, the double-quotes around name and content are optional if the value
 * does NOT contain any of the following characters: space, tab, new line, line feed:
 *
 * '<meta name="description" content="Course notes for WEB222">'
 * '<meta name=description content="Course notes for WEB222">'
 *
 * When creating your string, only include double-quotes when necessary.
 *
 * @param {string} name - the value for the name attribute
 * @param {string} content - the value for the content attribute
 * @returns {string} - a properly formatted <meta> tag
 ******************************************************************************/

function createMetaTag(name, content) {
  // Replace this comment with your code...
}

/*******************************************************************************
 * Problem 3: extract Date from date string
 *
 * A date string is expected to be formatted in one of the following formats:
 *
 * 1. YYYY-MM-DD
 * 2. DD-MM-YYYY
 *
 * Here, the Year (4 digits) may be listed first or last.  The Month (2 digits)
 * will always be in the middle position, and the Day (2 digits) will either
 * be last (when Year is first) or first (when Year is last).
 *
 * January 15, 2023 could therefore be represented in either of the following
 * formats:
 *
 * 2023-01-15
 * 15-01-2023
 *
 * Write a function, parseDateString() that accepts a date string of the formats
 * specified above, and returns a new JavaScript Date Object, set to the correct
 * day. In your solution, you will need to use use the following Date methods:
 *
 * - new Date() - creates a new Date Object
 * - setFullYear() - sets the Date Object's year value
 * - setMonth() - sets the Date Object's month value
 * - setDate() - sets the Date Object's day value
 *
 * To help developers using your function, you are also asked to provide detailed
 * error messages when the date string is formatted incorrectly.  We will use the
 * `throw` statement to throw a new Error object when a particular value is not
 * what we expect, see:
 * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/throw
 *
 * For example: parseDateString('01-01-01') should fail, because the year is
 * not 4 digits.
 *
 * Similarly, parseDateString('2021-1-01') should fail because
 * the day is not 2 digits, and parseDateString('2021-01-1') should fail because
 * the month is not 2 digits.
 *
 * Also, a totally invalid date string should also cause an exception to be thrown,
 * for example parseDateString(null) or parseDateString("this is totally wrong").
 *
 * @param {string} value - a date string
 * @returns {Date}
 ******************************************************************************/

function parseDateString(value) {
  // Replace this comment with your code...
}

/*******************************************************************************
 * Problem 4: format a Date Object to use a given date string format.
 *
 * Building on your work in Problem 3 above, we want to be able to take a Date
 * object, and format it into a string using one of the following 3 formats:
 *
 * 1. YYYY-MM-DD
 * 2. DD-MM-YYYY
 * 3. MM-DD-YYYY
 *
 * Meaning, Year (4 digits), Month (2 digits), Day (2 digits).
 *
 * Write a function, toDateString() that accepts a Date object and a date string
 * format (e.g., "YYYY-MM-DD", "DD-MM-YYYY", or "MM-DD-YYYY"), and returns a date
 * string formatted according to supplied format. Make sure your day and month
 * values are padded with a leading '0' if necessary (e.g., 03 vs. 3).
 *
 * If something other than a valid Date Object is passed as the first argument,
 * trying to call the Date methods will fail.  You should use try/catch and
 * throw a new Error object with an appropriate error message if this happens.
 * See https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/try...catch
 *
 * If the date string format is not one of the 3 listed above, throw a new Error
 * with an appropriate error message explaining the problem.
 *
 * NOTE: it should be possible to use parseDateString() from the previous question
 * and toDateString() to reverse each other. For example:
 *
 * toDateString(parseDateString('2021-01-29), "YYYY-MM-DD") should return '2021-01-29'
 * toDateString(parseDateString('2021-01-29), "DD-MM-YYYY") should return '29-01-2021'
 * toDateString(parseDateString('29-01-2021), "MM-DD-YYYY") should return '01-29-2021'
 *
 * @param {Date} value - a Date Object to be formatted
 * @param {string} format - a format string, one of "YYYY-MM-DD", "DD-MM-YYYY", or "MM-DD-YYYY"
 * @returns {string} - the formatted date string
 ******************************************************************************/

function toDateString(value, format) {
  // Replace this comment with your code...
}

/*******************************************************************************
 * Problem 5: parse a time duration
 *
 * Time duration is defined as a length of time expressed in hours, minutes, and
 * seconds. An example, the duration from 9:15 AM to 10:45 AM is:
 *
 *   Hours: 1
 *   Minutes: 30
 *   Seconds: 0
 *
 * A dataset includes thousands of time duration, stored as strings. However, over
 * the years, different authors have used slightly different formats.
 * All of the following are valid and need to be parsed:
 *
 * 1. "1:30:0"
 * 2. "1h30m0s"
 *
 * In the first case, the values are separated by `:`.  In the second, the values
 * are followed by the unit (h, m, s).
 *
 * Valid Hour values are positive integers between 0 and 24.
 *
 * Valid Minute values are positive integers between 0 and 59.
 *
 * Valid Second values are positive integers between 0 and 59.
 *
 * If the input duration is invalid, return the value `null`.
 *
 * Parse the value and return a new string in the following form:
 *
 * "(hours, minutes, seconds)"
 *
 * @param {string} value - a time duration string in one of the given forms
 * @returns {string|null} - a time duration formatted as "(hours, minutes, seconds)"
 *                          or `null` if the duration isn't valid/recognized
 */

function normalizeDuration(value) {
  // Replace this comment with your code...
}

/*******************************************************************************
 * Problem 6: format any number of durations as a list in a string
 *
 * You are asked to format time durations (hour, min, sec) in a list using your
 * normalizeDuration() function from problem 5.
 *
 * Where normalizeDuration() takes a single duration string, the formatDurations()
 * function takes a list of any number of duration strings, parses them,
 * filters out any invalid ones, and creates a list.
 *
 * For example: given the following durations, "1h13m2s" and "4:16:24",
 * a new list would be created of the following form "((1, 13, 2), (4, 16, 24))".
 *
 * Notice how the list has been enclosed in an extra set of (...) braces, and each
 * duration is separated by a comma and space.
 *
 * The formatDurations() function can take any number of arguments, but they must all
 * be strings.  If any of the values can't be parsed by normalizeDuration() (i.e., if
 * it returns null), skip the value.  For example:
 *
 * formatDurations("1h13m2s", "300:600:900", "4:16:24") should return
 * "((1, 13, 2), (4, 16, 24))" and skip the invalid duration.
 *
 * @param {number} arguments - any number of string duration arguments can be passed
 * @returns {string}
 ******************************************************************************/

function formatDurations(...values) {
  // Replace this comment with your code...
}

/*******************************************************************************
 * Problem 7: determine file type from a filename
 *
 * To identify the type of a file, the Operating System looks at the filename and
 * extension.  The OS needs to know the file type to open it with the correct
 * program.
 *
 * Write a function, typeFromFilename(), which should take a filename and return the
 * type of file it is (e.g., 'text', 'image', 'video', etc.), based on the
 * following extensions:
 *
 * - .txt, .rtf, .doc, .docx --> 'text'
 * - .jpg, .jpeg, .gif, .bmp, .ico, .cur, .png, .svg, .webp --> 'image'
 * - .mp3, .wav --> 'audio'
 * - .mp4, .webm, .mpeg, .avi --> 'video'
 * - .json --> 'data'
 * - .csv, .xls --> 'spreadsheet'
 * - .ttf, .woff --> 'font'
 * - .exe, .dll --> 'binary'
 * - .zip --> 'archive'
 *
 * NOTE: any other extension should return 'unknown', to indicate that it is an
 * unknown file type. You should also use 'unknown' if the file has no extension.
 *
 * @param {string} filename - a filename
 * @returns {string}
 ******************************************************************************/

function typeFromFilename(filename) {
  // Replace this comment with your code...
  // NOTE: Use a switch statement in your solution.
}

/*******************************************************************************
 * Problem 8: generate badge text and link from license code.
 *
 * Images, videos, and other resources on the web are governed by copyright.
 * Everything you find on the web is copyright to its creator automatically, and
 * you cannot reuse it unless you are granted a license to do so.
 *
 * Different licenses exist to allow creators to share their work. For example,
 * the Creative Commons licenses are a popular way to allow people to reuse
 * copyright material, see https://creativecommons.org/licenses/.
 *
 * Below is a list of license codes, and the associated badge text explaining the code:
 *
 * Code           License Name
 * ----------------------------------------------------------------------------
 * CC-BY:         Creative Commons Attribution License
 * CC-BY-NC:      Creative Commons Attribution-NonCommercial License
 * CC-BY-SA:      Creative Commons Attribution-ShareAlike License
 * CC-BY-ND:      Creative Commons Attribution-NoDerivs License
 * CC-BY-NC-SA:   Creative Commons Attribution-NonCommercial-ShareAlike License
 * CC-BY-NC-ND:   Creative Commons Attribution-NonCommercial-NoDerivs License
 *
 * NOTE: any other licenseCode should use the URL https://choosealicense.com/no-permission/
 * and the explanation text, "All Rights Reserved"
 *
 * Write a function, generateLicenseBadge(), which takes a license code string, and returns
 * an HTML link to the appropriate badge (i.e., image) URL, including the badge text.
 *
 * For example:
 *
 * generateLicenseBadge('CC-BY-NC') should return the following HTML string:
 *
 * '<a href="https://creativecommons.org/licenses/by-nc/4.0/"><img src="https://licensebuttons.net/l/by-nc/4.0/88x31.png" alt="Creative Commons Attribution-NonCommercial License"></a>'
 *
 * The URL is generated based on the license code:
 *
 * - remove the `CC-` prefix
 * - convert to rest to lower case
 * - create a license URL using the formatted code: https://creativecommons.org/licenses/[...here]/4.0/
 * - create a badge image URL using the formatted code: https://licensebuttons.net/l/[...here]/4.0/88x31.png
 * - create an <a> and <img> tag, using the license name as alt text
 *
 * You can read more about HTML image links at https://developer.mozilla.org/en-US/docs/Web/HTML/Element/img
 *
 * @param {string} licenseCode - a license code
 * @returns {string}
 ******************************************************************************/

function generateLicenseBadge(licenseCode) {
  // Replace this comment with your code...
}

/*******************************************************************************
 * Problem 9: Count the number of true and false values in a dataset
 *
 * A dataset contains fields that indicate a value is true or false.  However,
 * users have entered data in various formats and languages (English and French)
 * over the years, and the data is a mess. For example, the dataset contains all
 * of the following values:
 *
 * "True" values include: Yes, yes, YES, Y, Oui, oui, OUI, O, t, TRUE, true, True,
 * vrai, V, VRAI, 1, 2, ...any positive number
 *
 * "False" values include: No, no, NO, Non, non, NON, N, n, f, FALSE, false, False,
 * FAUX, faux, Faux, 0, -1, -2, ...any negative number
 *
 * Write two functions that work in similar ways: countTrue() and countFalse()
 * both take any number of string, number, or boolean values and count the
 * number of items that are either "true" or "false", according to the following rules:
 *
 * 1. If the value is already a Boolean (true or false) count it as true or false respectively
 * 2. If the value is one of the "true" type values, count it as true
 * 3. If the value is one of the "false" type values, count it as false
 * 4. If the value is none of the "true" or "false" values, ignore it
 *
 * Your countTrue() and countFalse() functions will have a lot of similarities.
 * Write a third function that can be re-used by countTrue() and countFalse()
 * to do the common part of this operation.  You shouldn't copy/paste any
 * code or share much logic between countTrue() and countFalse().
 *
 * @param {string|number|boolean} data - any number of strings, numbers, or booleans
 * @returns {number} - a count of true/false values (depending on which function)
 ******************************************************************************/

function countTrue(...values) {
  // Replace this comment with your code...
}

function countFalse(...values) {
  // Replace this comment with your code...
}

/*******************************************************************************
 * Problem 10 - build a query string
 *
 * Querying a web data API involves formatting a query string in a particular way.
 * As we know from week 1, a query string is a set of name=value pairs, that starts
 * with the ? character, and each pair is separated by the & character, see:
 * https://web222.ca/weeks/week01/#query-strings
 *
 * For example:
 *
 *   ?q=dog&sort=ascending includes q=dog and sort=ascending
 *   ?_encoding=UTF8&node=18521080011 includes both _encoding=UTF8 and also node=18521080011
 *
 * Write a buildQueryString() function to build a query string based on arguments
 * passed by the caller.
 *
 * The buildQueryString() function accepts the following arguments:
 *
 * - queryTerm: a search string, for example "butterfly" or "Horse-chestnut"
 * - sortOrder: a string indicating sort order, with possible values of `ascending` or `descending`
 * - count: a number from 10 to 200, indicating how many results to return per page
 *
 * Write an implementation of buildQueryString() that accepts arguments for all of the above
 * parameters, validates and formats them (e.g., encode the query, count must be between 10
 * and 200, etc), and returns a properly formatted query string.
 *
 * For example:
 *
 * buildQueryString('Monarch Butterfly', 'ascending', 25) would return the following query string:
 *
 * '?query_term=Monarch%20Butterfly&count=25
 *
 * NOTE: the default sort order is ascending, so it isn't included.  However, if we were to
 * specify 'descending', it would need to get added:
 *
 * buildQueryString('Monarch Butterfly', 'descending', 25) would return the following query string:
 *
 * '?query_term=Monarch%20Butterfly&count=25&descending
 *
 * NOTE: if any of the values passed to buildQueryString() are invalid, an Error should be thrown.
 *
 * NOTE: make sure you properly encode the query value, since query strings can't contain
 * spaces or other special characters. HINT: use the encodeURIComponent() function
 * to do this, see:
 *
 * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/encodeURIComponent
 *
 * @param {string} queryTerm the query to use.
 * @param {string} sortOrder the sort order to use, must be one of `ascending` or `descending`
 * @param {number} count the number of results per page, must be 10-200
 * @returns {string} the properly formatted query string
 ******************************************************************************/

function buildQueryString(queryTerm, sortOrder, count) {
  // Replace this comment with your code...
}

// Our unit test files need to access the functions we defined
// above, so we export them here.
exports.greeting = greeting;
exports.toCamelCase = toCamelCase;
exports.createMetaTag = createMetaTag;
exports.parseDateString = parseDateString;
exports.toDateString = toDateString;
exports.normalizeDuration = normalizeDuration;
exports.formatDurations = formatDurations;
exports.typeFromFilename = typeFromFilename;
exports.generateLicenseBadge = generateLicenseBadge;
exports.countTrue = countTrue;
exports.countFalse = countFalse;
exports.buildQueryString = buildQueryString;
