import { useState, useEffect } from "react";

export default function Clock({ locale }) {
    
  let [date, setDate] = useState(null);

  useEffect(() => {
    setDate(new Date());
    setInterval(() => {
      setDate(new Date());
    }, 1000);

    return () => {
      clearInterval();
    };
  }, []);

  return (
    <>
      <p>{date?.toLocaleTimeString(locale)}</p>
    </>
  );
}

Clock.defaultProps = {
  locale: "en-CA",
};
