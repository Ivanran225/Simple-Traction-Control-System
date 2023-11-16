'use client'
import Image from 'next/image'

export default function Button() {
  return (
  <div className="button-container">
    <div className="button-box">
      <button className="button">
        SHALOM
      </button>
      <button className="button">
        SHALOM
      </button>
      <button className="button">
        SHALOM
      </button>
    </div>
    <style jsx>{`
      .button-container {
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        background-color: #8FDECB;
        flex-direction: column;
        gap: 20px;
      }
      .button-box {
        display: flex;
        flex-direction: column;
        gap: 30px;
        padding: 40px;
        background-color: #FCF1D5;
        border-radius: 40px;
        background: #FCF1D2;
        box-shadow:  29px 29px 10px #58A8A7, 
        inset 4px 4px 5px 1px rgba(255, 255, 255, 0.5), 
        inset -4px -4px 5px #000000;
        border: 5px solid #150B3D;
      }
      .button {
        background-color: #273250;
        border: 5px solid #150B3D;
        border-radius: 50px;
        padding: 20px;
        width: 400px;
        color: orange;
        display: inline-block;
        font-size: 20px;
        text-align: left;
        cursor: pointer;
        transition: background-color 0.3s ease, box-shadow 0.3s ease, transform 0.3s ease;
        box-shadow: 10px 10px 5px 2px #C5B7A8, inset -4px -4px 2px #1B1538, inset 4px 4px 2px #435472; 
      }
      .button:active {
        box-shadow: 7px 7px 10px 1px #000000, inset -1px -1px 5px #000000, inset 2px 2px 5px #ffffff;
        transform: scale(0.97);
      }
    `}</style>
    </div>
  )
}