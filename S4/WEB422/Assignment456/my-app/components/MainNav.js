import React from "react";
import {
  Navbar,
  Nav,
  Form,
  FormControl,
  Button,
  Container,
} from "react-bootstrap";
import Link from "next/link";
import { useRouter } from "next/router";

export default function MainNav() {
  const router = useRouter();
  const [search, setSearch] = React.useState("");

  const submitForm = (e) => {
    e.preventDefault();
    router.push(`/artwork?title=true&q=${search}`);
  };

  return (
    <>
      <Navbar className="fixed-top navbar-dark bg-primary">
        <Container fluid>
          <Navbar.Brand>Chi-Wei Perng</Navbar.Brand>
          <Navbar.Toggle aria-controls="navbarScroll" />
          <Navbar.Collapse
            id="navbarScroll"
            className="justify-content-between"
          >
            <Nav>
              <Link href="/" passHref legacyBehavior>
                <a className="nav-link">Home</a>
              </Link>
              <Link href="/search" passHref legacyBehavior>
                <a className="nav-link">Advanced Search</a>
              </Link>
            </Nav>
            <Form className="d-flex ml-md-auto" onSubmit={submitForm}>
              <FormControl
                type="text"
                placeholder="Search"
                className="mr-sm-2"
                value={search}
                onChange={(e) => setSearch(e.target.value)}
              />
              <Button type="submit" variant="btn btn-success">
                Search
              </Button>
            </Form>
          </Navbar.Collapse>
        </Container>
      </Navbar>
      <br />
      <br />
    </>
  );
}
