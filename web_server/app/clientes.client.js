import Image from 'next/image'

export default function Button() {
  return (
    <div style={{ 
      display: 'flex', 
      justifyContent: 'center', 
      alignItems: 'center', 
      height: '100vh',
      backgroundColor: '#000000',
    }}>
      <button
        className="
        bg-gray-600 rounded-2xl p-5  
        text-white inline-block font-bold text-2xl text-center cursor-pointer 
        transition ease-in-out delay-150 
        hover:bg-gray-500 
        hover:translate-y-1 
        hover:scale-95
        hover:bg-gray-500 duration-300"
        style={{ 
          boxShadow: "6px 6px 2px 2px #666666, inset -2px -2px 5px #000000, inset 1px 1px 5px #ffffff"
        }}>
        SHALOM
      </button>
    </div>
  )
}