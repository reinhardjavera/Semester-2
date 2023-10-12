import React, { useState } from "react";
import "./styles.css";
export default function App() {
  const [thing, setThing] = useState([]);
  const url =
    "https://api.themoviedb.org/3/movie/top_rated?language=en-US&page=1";
  const options = {
    method: "GET",
    headers: {
      accept: "application/json",
      Authorization:
        "Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiI0OTE5YmVhZDliMjk5ODYzN2MyNGFmMWRjNzFlMmE1YiIsInN1YiI6IjY0NzYwZjk0ZGQyNTg5MDEwMTdmYjAwYSIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.6vNSUtV8yIzY68JSmZbqR0W8a7UX_IFIV22cPQOfvkI"
    }
  };
  fetch(url, options)
    .then((res) => res.json())
    .then((json) => {
      setThing(json.results);
    });
  const RenderThis = () => {
    return thing.map((val, index) => {
      return (
        <div>
          <h1>{val.original_title}</h1>
          <p>{val.overview}</p>
        </div>
      );
    });
  };
  return (
    <div className="App">
      <RenderThis />
    </div>
  );
}
