/* sort-array-of-objects.js
 * https://www.hackerrank.com/contests/7days-javascript/challenges/sort-array-of-objects
 * by @mabernardo
 */

function sortLibrary() {
    // var library is defined, use it in your code
    // use console.log(library) to output the sorted library data
    library.sort(function(a, b) { return a.title > b.title ? 1 : -1; });
    console.log(library);
} 

// tail starts here
var library = [
    {
        author: 'Bill Gates',
        title: 'The Road Ahead',
        libraryID: 1254
    },
    {
        author: 'Steve Jobs',
        title: 'Walter Isaacson',
        libraryID: 4264
    },
    {
        author: 'Suzanne Collins',
        title: 'Mockingjay: The Final Book of The Hunger Games',
        libraryID: 3245
    }
];

sortLibrary();
