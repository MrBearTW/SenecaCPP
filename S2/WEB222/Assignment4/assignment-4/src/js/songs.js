/**
 * songs.js
 *
 * The app's songs
 */

// -	Songs: pick a minimum of 20 songs by your chosen artists. Each song will belong to one of the artists.

/*
-	 id: a unique String that identifies this song.  For example: “s1” or “song-01” or “V1StGXR8”.  It doesn’t matter what format you choose as long as each song has its own, unique value.  Also, make sure the artist id and song id are different.
-	artistId: a String that indicates which artist this song belongs to
-	title: a short String that names the song
-	year: a String with the year (4 digits) that the song was recorded
-	duration: a Number of seconds (i.e., an Integer value) for the song’s length.  When we store time values, we often store them in seconds vs. floats, and convert them to minutes, seconds in the UI for display.
-	flagged: a Boolean that indicates whether this song has been flagged in the system, and should NOT be shown to users.  Make sure at least 2 of your songs have flagged set to true.

*/

window.songs = [
  {
    id: "s1",
    artistId: "a1",
    title: "Southbound Night Bus",
    year: "2017",
    duration: 186,
    flagged: true
  },
  { id: "s2", artistId: "a1", title: "Chen 52", year: "2016", duration: 338, flagged: false },
  {
    id: "s3",
    artistId: "a1",
    title: "Theme of Raid on Takao",
    year: "2018",
    duration: 268,
    flagged: false
  },
  { id: "s4", artistId: "a1", title: "Keep On Going", year: "2016", duration: 323, flagged: false },
  {
    id: "s5",
    artistId: "a1",
    title: "Stand Up Like A Taiwanese",
    year: "2019",
    duration: 200,
    flagged: false
  },
  { id: "s6", artistId: "a2", title: "Roll-Cigg", year: "2016", duration: 237, flagged: false },
  { id: "s7", artistId: "a2", title: "Chill Out", year: "2018", duration: 267, flagged: false },
  {
    id: "s8",
    artistId: "a2",
    title: "You are My Crazy Lover",
    year: "2019",
    duration: 256,
    flagged: false
  },
  { id: "s9", artistId: "a2", title: "Sin Man", year: "2021", duration: 298, flagged: false },
  {
    id: "s10",
    artistId: "a2",
    title: "Golden Spirit",
    year: "2021",
    duration: 217,
    flagged: false
  },
  { id: "s11", artistId: "a3", title: "Dong", year: "2004", duration: 291, flagged: false },
  {
    id: "s12",
    artistId: "a3",
    title: "Walking On Chung Hsiao East Road 9 Times",
    year: "2001",
    duration: 292,
    flagged: false
  },
  { id: "s13", artistId: "a3", title: "Love Me True", year: "2021", duration: 313, flagged: false },
  { id: "s14", artistId: "a3", title: "Cut Me Dead", year: "2021", duration: 306, flagged: false },
  { id: "s15", artistId: "a3", title: "Long Gone", year: "2020", duration: 277, flagged: false },
  { id: "s16", artistId: "a4", title: "Midway", year: "2016", duration: 311, flagged: false },
  {
    id: "s17",
    artistId: "a4",
    title: "Go Through the Night",
    year: "2021",
    duration: 230,
    flagged: false
  },
  { id: "s18", artistId: "a4", title: "Underwater", year: "2019", duration: 389, flagged: false },
  { id: "s19", artistId: "a4", title: "Quilt", year: "2018", duration: 260, flagged: true },
  { id: "s20", artistId: "a4", title: "Head&Body", year: "2014", duration: 315, flagged: false },
  {
    id: "s21",
    artistId: "a2",
    title: "King of Light",
    year: "2018",
    duration: 323,
    flagged: false
  },
  {
    id: "s22",
    artistId: "a1",
    title: "Island's Sunrise",
    year: "2014",
    duration: 293,
    flagged: false
  },
  {
    id: "s23",
    artistId: "a5",
    title: "Love You One More Time",
    year: "2021",
    duration: 307,
    flagged: false
  },
  {
    id: "s24",
    artistId: "a5",
    title: "Back Here Again",
    year: "2017",
    duration: 290,
    flagged: false
  },
  {
    id: "s25",
    artistId: "a5",
    title: "Waves Wandering",
    year: "2018",
    duration: 374,
    flagged: false
  },
  {
    id: "s26",
    artistId: "a5",
    title: "Oh Love, You Are Much Greater Than I Imagined ",
    year: "2021",
    duration: 279,
    flagged: false
  },
  {
    id: "s27",
    artistId: "a5",
    title: "Would You Want to Be My Girlfriend?",
    year: "2020",
    duration: 276,
    flagged: false
  }
];