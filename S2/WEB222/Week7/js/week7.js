function clickMe() {
  // alert("You clicked me!");
  var objp1 = document.querySelector("#p2");
  objp1.innerHTML = "<u> You clicked me!</u>";
}

function addList1() {
  var objList1 = document.querySelector("#list1");
  var input = "Lychee";

  objList1.innerHTML = `
    <ul>
        <li>Item 1</li>
        <li>Item 2</li>
        <li>${input}</li>
    </ul>`;
  // objList1.innerHTML += "<li>New Item</li>";
}

function addParagraph() {
  var newText = "Have fun";
  var objNewP = document.getElementById("newP1");
  var obj2 = document.createElement("p"); // <p> </p>
  var txtP = document.createTextNode(newText);
  obj2.appendChild(txtP);
  objNewP.appendChild(obj2);
}
