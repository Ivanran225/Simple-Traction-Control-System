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
        background-color: #122838;
        flex-direction: column;
        gap: 20px;
      }
      .button-box {
        display: flex;
        flex-direction: column;
        gap: 30px;
        padding: 30px;
        background-color: #223848; // Light grey background
        border-radius: 40px;
        background: #223848;
        box-shadow:  29px 29px 30px #1d303d,
                   -29px -29px 30px #274053;
      }
      .button {
        background-color: #324858;;
        border-radius: 50px;
        padding: 20px;
        width: 400px;
        color: orange;
        display: inline-block;
        font-size: 20px;
        text-align: left;
        cursor: pointer;
        transition: background-color 0.3s ease, box-shadow 0.3s ease, transform 0.3s ease;
        box-shadow: 12px 12px 10px 2px #000000, inset -2px -2px 5px #000000, inset 1px 1px 5px #ffffff; 
      }
      .button:active {
        box-shadow: 7px 7px 10px 1px #000000, inset -1px -1px 5px #000000, inset 2px 2px 5px #ffffff;
        transform: scale(0.95);
      }
    `}</style>
    </div>
  )
}