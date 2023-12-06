'use client'
import { redirect } from 'next/dist/server/api-utils';
import Image from 'next/image'
import React, { useState, useRef } from 'react';

export default function Button() {  
  const [ipAddress, setIpAddress] = useState('');
  const sliderRef = useRef<HTMLInputElement>(null); // Specify the type as HTMLInputElement
  const textSliderValueRef = useRef<HTMLElement>(null); // Specify the type as HTMLElement

  const handleIpChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    setIpAddress(event.target.value);
  };

  const handleButton1Click = () => {
    console.log('shalom');
  };

  const updateSliderPWM = () => {
    let sliderValue = sliderRef.current ? sliderRef.current.value : '';
    let ip = ipAddress;

    if (ip.match(/^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$/)) {
      var xhr = new XMLHttpRequest();
      xhr.open("GET", `http://${ip}/slider?value=${sliderValue}`, true);
      xhr.send();
      console.log(sliderValue);
    } else {
      console.log("invalid ip");
    }
  };
  return (
    <div className="button-container" style={{ backgroundColor:'#8FDECB'}}>
      <div className="button-box">
        <button className= "button" style={{ color: '#FFA500' }} onClick={handleButton1Click}>
          SHALOM
        </button>
        <button className="button" style={{ color: '#fd6d5d' }}>
          SHALOM
        </button>
        <button className="button" style={{ color: '#49B5BA' }}>
          SHALOM
        </button>

        <input
          type="text"
          value={ipAddress}
          onChange={handleIpChange}
          placeholder="IP Address"
          style={{
            backgroundColor: '#273250',
            border: '5px solid #150B3D',
            borderRadius: '50px',
            padding: '20px',
            width: '350px',
            color: 'orange',
            display: 'inline-block',
            fontSize: '20px',
            textAlign: 'left',
            cursor: 'pointer',
            transition: 'background-color 0.3s ease, box-shadow 0.3s ease, transform 0.3s ease',
            boxShadow: '10px 10px 5px 2px #C5B7A8, inset -4px -4px 2px #1B1538, inset 4px 4px 2px #435472',
          }}
        />
        <input
          type="range"
          min="-100"
          max="0"
          defaultValue="10"
          className="slider"
          style={{
            appearance: 'none',
            width: '385',
            height: '65px',
            background: '#273250',
            outline: 'none',
            opacity: '1',
            transition: '.2s',
            backgroundClip: 'padding-box',
            padding: '10 10px',
          }}
          ref={sliderRef}
          onChange={updateSliderPWM} 
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
        width: 400px; /* Full-width */
        height: 20px; /* Specified height */
        outline: none; /* Remove outline */
        opacity: 0.7; /* Set transparency (for mouse-over effects on hover) */
        -webkit-transition: .2s; /* 0.2 seconds transition on hover */
        transition: opacity .2s;
        border: 5px solid #150B3D;
        border-radius: 50px; /* Rounded edges */
        box-shadow: 10px 10px 5px 2px #C5B7A8, inset -4px -4px 2px #1B1538, inset 4px 4px 2px #435472; 
        position: relative;
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
        transform: translateY(-35%);
      }
      .slider:hover {
        opacity: 1; /* Fully visible on hover */
      }
      .slider::-webkit-slider-runnable-track {
        height: 10px; // Set the track height
        background: #150B3D; // Set the track color
        border-radius: 25px; // Round the corners
        box-shadow: inset 4px 4px 2px #000;
        margin-left: 20px;
        margin-right: 20px;
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