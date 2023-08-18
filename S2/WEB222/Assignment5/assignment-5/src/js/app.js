/**
 * WEB222 – Assignment 04
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       CHI-WEI PERNG
 *      Student ID: 121967228
 *      Date:       2023/07/21
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { artists, songs } = window;

// For debugging, display all of our data in the console. You can remove this later.
// console.log({ artists, songs }, "App Data");

//  Menu Navigation: Clickable Artist Names Dynamically Generated

//   1.	Create an event handler to run when the page is loaded.  Make sure you don’t do anything to the DOM until it’s fully loaded.  Your function should do the following:
function createButtons() {
  // a.	Create all of the buttons for your store’s Artists
  //    i.	Loop through all of your Artist objects and create a <button> element for each, adding it to the <nav id=”menu”>…</nav>
  const menu = document.querySelector("#menu");
  for (const artist of artists) {
    const button = document.createElement("button");

    //    ii.	Use each Artist’s name for the button’s text
    button.textContent = artist.name;

    //    iii.	When the button is clicked, show that Artists Name, Links, and Songs.  See below for more details.
    button.addEventListener("click", () => loadArtist(artist));
    menu.appendChild(button);
  }

  // b.	Show a list of Songs in the <tbody>…</tbody> of your Table.  By default, you should use your first Artist on load.  See below for more details
}

// Dynamically update the selected category title

// 2.	Write a function that will show a list of songs in the <tbody>…</tbody> based on the chosen Artist:

function loadArtist(artist = artists[0]) {
  //   a.	Update the text of the Selected Artist above your table with the Artist’s Name and create anchor elements for all of the Artists Links (i.e., you should be able to open these links to see more info about the artist)
  const selectedArtist = document.querySelector("#selected-artist");

  // Add the artist name
  selectedArtist.innerHTML = artist.name;
  // Separate the artist name and links with a pipe (-->) character
  selectedArtist.innerHTML += " ( ";

  for (const link of artist.links) {
    const a = document.createElement("a");
    a.textContent = link.name;
    a.href = link.url;
    selectedArtist.appendChild(a);
    // if it's not the last link, add a seperator
    if (link !== artist.links[artist.links.length - 1]) {
      const seperator = document.createElement("span");
      seperator.textContent = " , ";
      selectedArtist.appendChild(seperator);
    }
  }
  selectedArtist.innerHTML += " ) ";

  //   b.	Clear the current <tr>…</tr> rows from the <tbody>…</tbody>. HINT: innerHTML = “”
  const tbody = document.querySelector(".card-container");
  tbody.innerHTML = "";

  //   c.	Filter your Songs Array (i.e., use Array.prototype.filter()) to get:
  //     i.	All Songs for the chosen Artist. HINT: use Array.prototype.includes()
  //     ii.	All Songs that are NOT flagged
  const filteredSongs = songs.filter((song) => {
    return song.artistId === artist.id && !song.flagged;
  });

  //   d.	Loop (use Array.prototype.forEach()) over your filtered song list and add them to the table’s body using DOM methods (i.e., not innerHTML):
  //     i.	Create a <tr> element
  //     1.	Add a click handler to your <tr> that will console.log() the song whenever the user clicks it
  //     ii.	Create <td> elements for the song’s name, year, and duration. Convert the duration in seconds to a value in mintues:seconds
  //     iii.	Append these <td> elements to the <tr>
  //     iv.	Append this <tr> to the <tbody>
  filteredSongs.forEach((song) => {
    // const tr = document.createElement("tr");
    // tr.addEventListener("click", () => console.log(song)); // Clicking Anywhere On A Row should console.log()
    // const tdTitle = document.createElement("td");
    // tdTitle.textContent = song.title;
    // const tdYear = document.createElement("td");
    // tdYear.textContent = song.year;
    // const tdDuration = document.createElement("td");
    // tdDuration.textContent = `${Math.floor(song.duration / 60)}:${song.duration % 60}`;
    // tr.appendChild(tdTitle);
    // tr.appendChild(tdYear);
    // tr.appendChild(tdDuration);
    // tbody.appendChild(tr);
    createSongCard(song);
  });
}

// In your solution, you will likely require all of the following:

// -	console.log() and NOTE that you can log Objects like so: console.log({ object })
// -	document.querySelector() to find elements in the DOM
// -	document.createElement() to create new DOM elements
// -	node.appendChild() to add an element as a child of a DOM node
// -	element.innerHTML to modify the HTML content of an element.  Don’t overuse this!

// You are encouraged to use what you learned in the first 3 assignments and write proper functions and semantic HTML.

/*
6.	Remove the card’s HTML you wrote earlier and write a function in JavaScript that creates them dynamically instead.  Your function should accept a song Object from your songs array and create a card in the DOM, using the HTML and class names you wrote above.  Here’s some code to get you started:

  <div class="song-card">
    <time class="card-year">2011</time>
    <img
    src="https://chthonic.tw/wp-content/uploads/2023/05/CHTHONIC_Collage_megaport_cover.jpeg"
    alt="Chthonic"
    class="card-image"
    />
    <h2 class="card-title">Takasago Army</h2>
    <span class="card-duration">4:30</span>
  </div>

*/
function createSongCard(song) {
  const cardContainer = document.querySelector(".card-container");
  const songCard = document.createElement("div");

  songCard.classList.add("song-card");

  const cardYear = document.createElement("time");
  cardYear.classList.add("card-year");
  cardYear.textContent = song.year;
  const cardImage = document.createElement("img");
  // Use imageUrl from the song object
  cardImage.classList.add("card-image");
  cardImage.src = song.imageUrl;
  cardImage.alt = song.title;

  const cardTitle = document.createElement("h2");
  cardTitle.classList.add("card-title");
  cardTitle.textContent = song.title;
  const cardDuration = document.createElement("span");
  cardDuration.classList.add("card-duration");
  cardDuration.textContent = `${Math.floor(song.duration / 60)}:${song.duration % 60}`;
  songCard.appendChild(cardYear);
  songCard.appendChild(cardImage);
  songCard.appendChild(cardTitle);
  songCard.appendChild(cardDuration);

  // append card to the card-container
  cardContainer.appendChild(songCard);
}

function onload() {
  createButtons();
  loadArtist();
}

// When the page is loaded, run the onload function
window.addEventListener("load", onload);
