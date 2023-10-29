/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [`./views/*.html`], // all .html files
  theme: {
    extend: {},
  },
  daisyui: {
    themes: ["autumn"],
  },
  plugins: [require("@tailwindcss/typography"), require("daisyui")],
};
