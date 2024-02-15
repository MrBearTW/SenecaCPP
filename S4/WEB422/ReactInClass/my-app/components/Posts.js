import useSWR from "swr";

const fetcher = (url) => fetch(url).then((res) => res.json());

export default function Posts() {
  const { data, err, isLoading } = useSWR(
    "https://jsonplaceholder.typicode.com/posts",
    fetcher
  );

  function handleClick(e, clickedId) {
    console.log(clickedId);
  }

  return (
    <>
      <table>
        <thead>
          <tr>
            <th>User ID</th>
            <th>Title</th>
            <th>Body</th>
          </tr>
        </thead>
        <tbody>
          {isLoading ? (
            <tr>
              <td colSpan="3">
                <strong>Loading...</strong>
              </td>
            </tr>
          ) : (
            <>
              {data.map((post) => (
                <tr key={post.id} onClick={(e) => handleClick(e, post.id)}>
                  <td>{post.userId}</td>
                  <td>{post.title}</td>
                  <td>{post.body}</td>
                </tr>
              ))}
            </>
          )}
        </tbody>
      </table>
    </>
  );
}
