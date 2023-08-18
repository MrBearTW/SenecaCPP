/**
 * artists.js
 *
 * The app's list of Artists
 */

// -	Artists: which music artists/bands does your app include?  Based on your chosen music genre, pick at least 3 artists that make this type of music.  No two students can use the exact same set of artists.

/*
Artists

Each artist needs three things:

-	id: a unique String that identifies this artist.  If two artists have the same name, we need a way to tell them apart.  For example, you could use: “a1” or “artist-01” or “V1StGXR8”.  It doesn’t matter what format you choose as long as each artist has a unique value. 
-	name: a human-readable String meant for display.  While the id is a unique key for the data used by programs, the name is meant to be shown to a user.
-	links: an Array of Objects containing one or more links for this artist.  Maybe they have their own web site, social media, Wikipedia page, etc.  Make sure each artist has at least 2 links.  Each Object in this Array will have the following properties:
  o	url – a String with a URL (e.g., an Instagram URL) 
  o	name – a String with a friendly name for what the link is (e.g., “Instagram”)

*/

window.artists = [
  {
    id: "a1",
    name: "Fire EX.",
    links: [
      { url: "https://www.fireex.com.tw/", name: "Official Website" },
      { url: "https://twitter.com/fireextaiwan", name: "Twitter" },
      { url: "https://www.instagram.com/fireex_official/", name: "Instagram" }
    ]
  },
  {
    id: "a2",
    name: "AmazingShow",
    links: [
      { url: "https://amazingshowtw.com/", name: "Official Website" },
      { url: "https://www.instagram.com/amazingshowtw/", name: "Instagram" },
      {
        url: "https://www.youtube.com/c/%E7%BE%8E%E7%A7%80%E9%9B%86%E5%9C%98AmazingShow/featured",
        name: "YouTube"
      }
    ]
  },
  {
    id: "a3",
    name: "Power Station",
    links: [
      { url: "https://www.youtube.com/channel/UCErZheK57jyQrLo_rJO0D5A", name: "YouTube" },
      { url: "https://www.instagram.com/powerstation_official/", name: "Instagram" }
    ]
  },
  {
    id: "a4",
    name: "Elephant Gym",
    links: [
      { url: "https://elephantgym.co/", name: "Official Website" },
      { url: "https://www.instagram.com/elephant_gym_official/", name: "Instagram" },
      { url: "https://www.youtube.com/channel/UCyCarLRHBVJYXJ3L2uuEEQg", name: "YouTube" }
    ]
  },
  {
    id: "a5",
    name: "EggPlantEgg",
    links: [
      { url: "https://www.youtube.com/channel/UCXBcSkBS763VgEmoKYUxfMg", name: "YouTube" },
      { url: "https://www.instagram.com/eggplantegg_tw/", name: "Instagram" }
    ]
  }
];
