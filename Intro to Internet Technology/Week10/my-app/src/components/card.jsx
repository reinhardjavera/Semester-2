import React from "react";

const Card = (props) => {
    return (
        <div id={props.id} className="card">
            <div className="container-card">
                <div className="emojis">
                    <h2>{props.emoji}</h2>
                </div>
                <div className="name">
                    <p style={{ textAlign: "center" }}>
                    <b>{props.name}</b>
                    </p>
                </div>
                <div className="meanings">
                    <p style={{ textAlign: "center" }}>{props.meaning}</p>
                </div>
            </div>
        </div>
    );
}


export default Card;