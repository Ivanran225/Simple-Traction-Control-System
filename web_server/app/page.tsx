'use client'
import Image from 'next/image'
//fd6d5d
export default function Button() {
  return (
    <div className="button-container">
      <div className="button-box">
        <button className="button" style={{ color: '#FFA500' }}>
          SHALOM
        </button>
        <button className="button" style={{ color: '#fd6d5d' }}>
          SHALOM
        </button>
        <button className="button" style={{ color: '#49B5BA' }}>
          SHALOM
        </button>
        
        <input
          type="range"
          min="-100"
          max="0"
          defaultValue="0"
          className="slider"
          style={{
            appearance: 'none',
            width: '100%',
            height: '60px',
            background: '#273250',
            outline: 'none',
            opacity: '1',
            transition: '.2s',
          }}
/>

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
        //padding-right: 80px; // Increased Right padding for slider
        background-color: #FCF1D5;
        border-radius: 40px;
        background: #FCF1D2;
        box-shadow:  29px 29px 10px #58A8A7, 
        inset 80px 80px 300px #ffffff80, 
        inset -60px -60px 300px #00000040;
        border: 5px solid #150B3D;
        position: relative;
      }    
      .slider {
        width: 100%; /* Full-width */
        height: 20px; /* Specified height */
        outline: none; /* Remove outline */
        opacity: 0.7; /* Set transparency (for mouse-over effects on hover) */
        -webkit-transition: .2s; /* 0.2 seconds transition on hover */
        transition: opacity .2s;
        border: 5px solid #150B3D;
        border-radius: 50px; /* Rounded edges */
        box-shadow: 10px 10px 5px 2px #C5B7A8, inset -4px -4px 2px #1B1538, inset 4px 4px 2px #435472; 
        position: relative;
        z-index: 1;
      }
      .slider::before {
        content: "";
        position: absolute;
        top: 50%;
        left: 0;
        width: 100%;
        height: 2px;
        background: repeating-linear-gradient(
          to right,
          #150B3D 0,
          #150B3D 20px,
          transparent 20px,
          transparent 40px
          );
        z-index: 2;
      }
      .slider::-webkit-slider-thumb {
        z-index: 3;
        -webkit-appearance: none; /* Override default look */
        appearance: none;
        width: 60px; /* Set a specific slider handle width */
        height: 40px; /* Slider handle height */
        background: linear-gradient(45deg, #ED6963 25%, #FFA500 25%, #FFA500 50%, #ED6963 50%, #ED6963 75%, #FFA500 75%, #FFA500);
        background-size: 20px 20px;
        border: 3px solid #58A8A7;
        border-radius: 25px; /* Remove rounded edges */
        cursor: pointer; /* Cursor on hover */
        margin: 0; /* Remove default margin */
        box-shadow: 2px 2px 2px 1px #000;
      }
      .slider:hover {
        opacity: 1; /* Fully visible on hover */
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
        box-shadow: 7px 7px 10px 1px #C5B7A8, inset -3px -3px 5px #1B1538, inset 5px 5px 2px #435472;
        transform: scale(0.97);
      }
    `}</style>
    </div>
  )
}