import Image from 'next/image'

export default function ondas() {
  return (
    <button
      className="
      bg-gray-600 border-4 border-black rounded-lg p-5 
      text-white inline-block font-bold text-2xl text-center cursor-pointer 
      transition ease-in-out delay-150 
      hover:bg-gray-500 
      hover:translate-y-1 
      hover:scale-100 hover:bg-indigo-500 duration-300 ..."
      style={{ boxShadow: "8px 8px 0px 0px #000000" }}>
      Click
    </button>
  )
}
