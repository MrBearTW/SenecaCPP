import React from "react";
import useSWR from "swr";
import { Card, Button } from "react-bootstrap";
import Link from "next/link";
import Error from "next/error";

export default function ArtworkCard({ objectID }) {
  const { data, error } = useSWR(
    `https://collectionapi.metmuseum.org/public/collection/v1/objects/${objectID}`
  );

  if (error) {
    return <Error statusCode={404} />;
  }

  if (data) {
    return (
      <>
        <Card>
          <Card.Img
            variant="top"
            src={
              data.primaryImageSmall ||
              "https://via.placeholder.com/375x375.png?text=[+Not+Available+]"
            }
          />
          <Card.Body>
            <Card.Title>{data.title || "N/A"}</Card.Title>
            <Card.Text>
              <strong>Date:</strong> {data.objectDate || "N/A"}
              <br />
              <strong>Classification:</strong> {data.classification || "N/A"}
              <br />
              <strong>Medium:</strong> {data.medium || "N/A"}
            </Card.Text>
            <Link href={`/artwork/${objectID}`} passHref>
              <Button variant="primary" class="btn btn-outline-primary">
                ID: {objectID}
              </Button>
            </Link>
          </Card.Body>
        </Card>
      </>
    );
  }

  return null;
}
