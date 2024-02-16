import { useRouter } from "next/router";

export default function Products() {
  const router = useRouter();

  const { page } = router.query;

  if (page) {
    return (
      <>
        <h1>Products on Page {page}</h1>;
      </>
    );
  } else {
    return (
      <>
        <h1>All Products</h1>;
      </>
    );
  }
}
