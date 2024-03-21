import React from "react";
import { useRouter } from "next/router";
import ArtworkCardDetail from "../../components/ArtworkCardDetail";

export default function ArtworkById() {
  const router = useRouter();
  const { objectID } = router.query;

  return <ArtworkCardDetail objectID={objectID} />;
}
