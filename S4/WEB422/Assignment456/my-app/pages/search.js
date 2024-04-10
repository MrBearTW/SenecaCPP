import React from "react";
import { useRouter } from "next/router";
import { Form, Button, Row, Col } from "react-bootstrap";
import { useForm } from "react-hook-form";
import { useAtom } from "jotai";
import { searchHistoryAtom } from "@/store";

export default function AdvancedSearch() {
  const router = useRouter();
  const {
    register,
    handleSubmit,
    formState: { errors },
  } = useForm();

  const [searchHistory, setSearchHistory] = useAtom(searchHistoryAtom);

  const submitForm = (data) => {
    let queryString = "";
    queryString += "searchBy=true";
    queryString += data.geoLocation ? `&geoLocation=${data.geoLocation}` : "";
    queryString += data.medium ? `&medium=${data.medium}` : "";
    queryString += `&isOnView=${data.isOnView}`;
    queryString += `&isHighlight=${data.isHighlight}`;
    queryString += `&q=${data.q}`;
    router.push(`/artwork?${queryString}`);
    setSearchHistory((current) => [...current, queryString]);
  };

  return (
    <>
      <Row className="main-content">
        <Col>
          <h1>Advanced Search</h1>
          <Form onSubmit={handleSubmit(submitForm)}>
            <Form.Group className="mb-3">
              <Form.Label>Search Query</Form.Label>
              <Form.Control
                type="text"
                placeholder="Search"
                {...register("q", { required: true })}
                className={errors.q ? "is-invalid" : ""}
              />
              {errors.q && (
                <div className="invalid-feedback">This field is required</div>
              )}
            </Form.Group>
            <Row>
              <Col md={4}>
                <Form.Group className="mb-3">
                  <Form.Label>Search By</Form.Label>
                  <Form.Select {...register("searchBy")}>
                    <option value="title">Title</option>
                    <option value="tags">Tags</option>
                    <option value="artistOrCulture">Artist or Culture</option>
                  </Form.Select>
                </Form.Group>
              </Col>
              <Col md={4}>
                <Form.Group className="mb-3">
                  <Form.Label>Geo Location</Form.Label>
                  <Form.Control
                    type="text"
                    placeholder="Geo Location"
                    {...register("geoLocation")}
                  />
                </Form.Group>
                <small class="text-muted form-text">
                  Case Sensitive String (ie "Europe", "France", "Paris",
                  "China", "New York", etc.), with multiple values separated by
                  the | operator
                </small>
              </Col>

              <Col md={4}>
                <Form.Group className="mb-3">
                  <Form.Label>Medium</Form.Label>
                  <Form.Control
                    type="text"
                    placeholder="Medium"
                    {...register("medium")}
                  />
                </Form.Group>
                <small class="text-muted form-text">
                  Case Sensitive String (ie "Europe", "France", "Paris",
                  "China", "New York", etc.), with multiple values separated by
                  the | operator
                </small>
              </Col>
            </Row>
            <Form.Group className="mb-3">
              <Form.Check
                type="checkbox"
                label="Highlighted"
                {...register("isHighlight")}
              />
            </Form.Group>
            <Form.Group className="mb-3">
              <Form.Check
                type="checkbox"
                label="Currently on View"
                {...register("isOnView")}
              />
            </Form.Group>
            <Button variant="primary" type="submit">
              Submit
            </Button>
          </Form>
        </Col>
      </Row>
    </>
  );
}
