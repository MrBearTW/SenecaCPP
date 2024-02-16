// import { useRouter } from "next/router";
// import useSWR from "swr";
// import Error from "next/error";

// const fetcher = (url) =>
//   fetch(url).then((res) => {
//     if (res.ok) {
//       return res.json();
//     } else {
//       return Promise.reject(res.status);
//     }
//   });

// export default function Post() {
//   const router = useRouter();

//   const { id } = router.query;

//   const { data, error, isLoading } = useSWR(
//     `https://jsonplaceholder.typicode.com/posts/${id}`,
//     fetcher
//   );

//   if (isLoading) {
//     return null;
//   } else {
//     if (error) {
//       return (
//         <>
//           <Error status={404} />
//         </>
//       );
//     } else {
//       return (
//         <>
//           <strong>User ID:</strong> {data.userId}
//           <br />
//           <strong>Title:</strong> {data.title}
//           <br />
//           <strong>Body:</strong> {data.body}
//           <br />
//         </>
//       );
//     }
//   }
// }

// Static Post Page

export async function getStaticPaths() {
  // pre-render and support post/1 through post/5 only
  return {
    paths: [
      { params: { id: "1" } },
      { params: { id: "2" } },
      { params: { id: "3" } },
      { params: { id: "4" } },
      { params: { id: "5" } },
    ],
    fallback: true, // any pages not identified above, will result in a 404 error, ie post/6
  };
}

export async function getStaticProps(context) {
  const res = await fetch(
    `https://jsonplaceholder.typicode.com/posts/${context.params.id}`
  );

  if (res.ok) {
    const data = await res.json();
    return { props: { staticPost: data } };
  } else {
    return {
      notFound: true,
    };
  }
}

export default function Post({staticPost}) {
  if (staticPost) {
    return (
      <>
        <strong>User ID:</strong> {staticPost.userId}
        <br />
        <strong>Title:</strong> {staticPost.title}
        <br />
        <strong>Body:</strong> {staticPost.body}
        <br />
      </>
    );
  } else {
    return null;
  }
}
