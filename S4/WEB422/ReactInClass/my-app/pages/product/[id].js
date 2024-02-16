import { useRouter } from "next/router";

export default function Product() {
  const router = useRouter();
  //   const id = router.query.id;
  const { id } = router.query;

  return (
    <>
      <h1>Product {id}</h1>
    </>
  );
}
