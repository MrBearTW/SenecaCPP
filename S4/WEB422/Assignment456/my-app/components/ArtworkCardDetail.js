import React from "react";
import useSWR from "swr";
import { Card, Button } from "react-bootstrap";
import Error from "next/error";
import { useAtom } from "jotai";
import { favouritesAtom } from "../store";

export default function ArtworkCardDetail({ objectID }) {
  const { data, error } = useSWR(
    objectID
      ? `https://collectionapi.metmuseum.org/public/collection/v1/objects/${objectID}`
      : null
  );

  const [favouritesList, setFavouritesList] = useAtom(favouritesAtom);
  const [showAdded, setShowAdded] = React.useState(
    favouritesList.includes(objectID)
  );

  const favouritesClicked = () => {
    if (showAdded) {
      setFavouritesList((current) => current.filter((fav) => fav != objectID));
      setShowAdded(false);
    } else {
      setFavouritesList((current) => [...current, objectID]);
      setShowAdded(true);
    }
  };

  if (error) {
    return <Error statusCode={404} />;
  }

  if (data) {
    return (
      <>
        <br />
        <Card>
          {data.primaryImage && (
            <Card.Img variant="top" src={data.primaryImage} />
          )}
          <Card.Body>
            <Card.Title>{data.title || "N/A"}</Card.Title>
            <Card.Text>
              <strong>Date:</strong> {data.objectDate || "N/A"}
              <br />
              <strong>Classification:</strong> {data.classification || "N/A"}
              <br />
              <strong>Medium:</strong> {data.medium || "N/A"}
              <br />
              <br />
              <strong>Artist:</strong> {data.artistDisplayName || "N/A"}
              {data.artistWikidata_URL && (
                <a>
                  &nbsp;( &nbsp;
                  <a
                    href={data.artistWikidata_URL}
                    target="_blank"
                    rel="noreferrer"
                  >
                    wiki
                  </a>
                  &nbsp;)
                </a>
              )}
              <br />
              <strong>Credit Line:</strong> {data.creditLine || "N/A"}
              <br />
              <strong>Dimensions:</strong> {data.dimensions || "N/A"}
              <br />
            </Card.Text>
            <Button
              variant={showAdded ? "primary" : "outline-primary"}
              onClick={favouritesClicked}
            >{`+ Favourite ${showAdded ? "(added)" : ""}`}</Button>
          </Card.Body>
        </Card>
      </>
    );
  }

  return null;
}
