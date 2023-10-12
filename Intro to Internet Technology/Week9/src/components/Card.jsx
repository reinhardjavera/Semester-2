import React from "react";

function Cards(props){
    return (
        <div class="card">
            <div class="container-card">
                <div className="texts">
                    <div className="names">
                        <h2 style={{margin:0, marginTop:16, marginBottom:60,}}>{props.name}</h2>
                    </div>
                    <div className="phones">
                        <p style={{marginTop:80,}}>{props.phone}</p>
                    </div>
                    <div className="emails">
                        <p>{props.email}</p>
                    </div>
                </div>
                <div className="images" style={{marginLeft: 50, marginBottom: 50}}>
                    <img src={props.imgURL} alt="" style={{height: 150, width: 150, borderRadius: 100}}></img>
                </div>
            </div>
        </div>
    )
}

export default Cards;