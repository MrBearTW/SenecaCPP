import { useState } from "react";

export default function Home() {

  const [firstName, setFirstName] = useState("Homer Simpson");

  function handleSubmit(e){
    e.preventDefault();
    console.log("form submitted");
    console.log(firstName);
  }

  return (
    <>
      <h2>Home (Controlled Component)</h2>

      <form onSubmit={handleSubmit}>
        First Name<br />
        <input type="text" value={firstName} onChange={e=>setFirstName(e.target.value)} name="firstName" /><br /><br />
        <button type="submit">Submit</button>
      </form>
    </>
  );
}
