import { useRouter } from "next/router";    
import Link from "next/link";

export default function Layout({ children }) {



    const router = useRouter();

    function navigateDashboard(){
        //console.log("TODO: Navigate to Dashboard");
        router.push("/dashboard");
    }

  return (
    <>
      <h1>Next.js Routing Practice</h1>
      <Link href="/">Home</Link> | <Link href="/about">About</Link>|{" "}
      <span onClick={navigateDashboard}>Dashboard</span>|{" "}
      <Link href="/product/5">Product 5 (demo)</Link> |{" "}
      <Link href="/post/3">Post 3 (demo)</Link>

      
      <hr />
      {children}
    </>
  );
}
