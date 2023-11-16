'use client'
import Image from 'next/image'

export default function Button() {
  return (
    <div className="button-container">
      <button className="button">
        SHALOM
      </button>
      <button className="button">
        SHALOM
      </button>
      <button className="button">
        SHALOM
      </button>
      <style jsx>{`
        .button-container {
          display: flex;
          justify-content: center;
          align-items: center;
          height: 100vh;
          background-color: #223848;
          flex-direction: column;
          gap: 20px;
        }
        .button {
          background-color: #324858;;
          border-radius: 50px;
          padding: 20px;
          width: 400px;
          color: orange; // Changed color to orange
          display: inline-block;
          font-size: 20px;
          text-align: left; // Aligned text to the left
          cursor: pointer;
          transition: background-color 0.3s ease, box-shadow 0.3s ease, transform 0.3s ease; // Added transition for transform
          box-shadow: 12px 12px 10px 2px #000000, inset -2px -2px 5px #000000, inset 1px 1px 5px #ffffff; 
        }
        .button:active {
          box-shadow: 7px 7px 10px 1px #000000, inset -1px -1px 5px #000000, inset 2px 2px 5px #ffffff;
          transform: scale(0.99);
        }
`}</style>
    </div>
  )
}