import ClickCounter from "@/components/ClickCounter";
import Clock from "@/components/Clock";
import FlintstonesTable from "@/components/FintstonesTable";
import Hello from "@/components/Hello";
import Post from "@/components/Post";
import Posts from "@/components/Posts";
import RandomNumbers from "@/components/RandomNumbers";
import Component1 from "@/components/Component1";
import ComponentA from "@/components/ComponentA";

export function getStaticProps() {
  return new Promise((resolve, reject) => {
    fetch("https://jsonplaceholder.typicode.com/posts/1")
      .then((res) => res.json())
      .then((data) => {
        resolve({ props: { staticPost: data } });
      });
  });
}

export default function Home(props) {
  return (
    <>
      {/* ---------- Week 8 ---------- */}
      <Component1 />
      <br />
      <ComponentA />

      {/* ---------- Week 4 class ---------- */}
      <Posts />
      <hr />
      <FlintstonesTable />
      <hr />
      <Post data={props.staticPost} />
      <hr />
      <RandomNumbers />
      <hr />
      <ClickCounter />
      <br />
      <ClickCounter start={5} />

      {/* ---------- Week 4 class ---------- */}

      {/* ---------- Week 3 class ---------- */}
      <Clock />
      <Clock locale="fr-CA" />
      {/* <Clock locale="zh_Hant" /> */}
      <Clock locale="ja" />
      <Clock locale="ko-kr" />

      <p>Home Page</p>
      <hr />
      <p>Home Page3</p>

      <Hello text="word from index" img="https://via.placeholder.com/150" />
      <hr />
      <Hello
        text="word from index2"
        img="https://cdn.iconscout.com/icon/free/png-256/free-dog-2194-1131172.png"
      />
      <hr />
      <Hello />
      {/* ---------- Week 3 class ---------- */}
    </>
  );
}
