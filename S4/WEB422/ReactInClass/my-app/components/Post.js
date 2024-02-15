// Use fetch --------------------------------------------

// import { useState, useEffect } from "react";

// export default function Post() {
//   const [post, setPost] = useState({});

//   useEffect(() => {
//     fetch("https://jsonplaceholder.typicode.com/posts/1")
//       .then((response) => response.json())
//       .then((data) => setPost(data));
//   }, []);

//   return (
//     <>
//       <h1>Post</h1>
//       <strong>User ID:</strong> {post.userId} <br />
//       <strong>Title:</strong> {post.title} <br />
//       <strong>Body:</strong> {post.body} <br />
//     </>
//   );
// }




// Use swr --------------------------------------------

// import useSWR from "swr";

// const fetcher = (url) => fetch(url).then((res) => res.json());

// export default function Post() {
//   const { data, error, isLoading } = useSWR(
//     "https://jsonplaceholder.typicode.com/posts/1",
//     fetcher
//   );

//   if (isLoading) {
//     return <p>Loading...</p>;
//   } else {
//     return (
//       <>
//         <h1>useSWR sample</h1>
//         <strong>User ID:</strong> {data?.userId} <br />
//         <strong>Title:</strong> {data?.title} <br />
//         <strong>Body:</strong> {data?.body} <br />
//       </>
//     );
//   }
// }


// Use staticProps --------------------------------------------

export default function Post({data}){
    return (<>
        <strong>User ID</strong>: {data?.userId}<br />
        <strong>Title</strong>: {data?.title}<br />
        <strong>Body</strong>: {data?.body}
    </>);  
}