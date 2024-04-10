import { Row, Col, Card } from "react-bootstrap";
import ArtworkCard from "@/components/ArtworkCard";
import { useAtom } from "jotai";
import { favouritesAtom } from "@/store";

export default function Favourites() {
  const [favouritesList] = useAtom(favouritesAtom);
  
  return (
    <>
      <div>
        {favouritesList.length === 0 ? (
          <Card body>
            <h3>Nothing Here</h3>
            <div>Try adding some artwork to your favourites</div>
          </Card>
        ) : (
          <Row className="row-cols-1 row-cols-md-2 row-cols-lg-3 g-4">
            {favouritesList.map((objectID) => (
              <Col key={objectID}>
                <ArtworkCard objectID={objectID} />
              </Col>
            ))}
          </Row>
        )}
      </div>
    </>
  );
}
